#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <algorithm>
#include <QDebug>

ResultsWindow::ResultsWindow(const QStringList &players, const QVector<int> &scores, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);

    // Устанавливаем стиль окна
    this->setStyleSheet("QDialog { background-color: #1a1a2e; font-family: 'Segoe UI', Arial, sans-serif; }");

    setWindowTitle("🏆 Результаты игры");
    setMinimumSize(800, 600);

    // Получаем отсортированные результаты
    QVector<QPair<QString, int>> sortedResults = getSortedResults(players, scores);

    // Настраиваем таблицу результатов
    setupResultsTable(sortedResults);

    // Подключаем кнопку закрытия
    connect(ui->closeButton, &QPushButton::clicked, this, &ResultsWindow::on_closeButton_clicked);
}

QVector<QPair<QString, int>> ResultsWindow::getSortedResults(const QStringList &players, const QVector<int> &scores) const
{
    QVector<QPair<QString, int>> results;

    // Собираем пары игрок-очки
    for (int i = 0; i < players.size(); ++i) {
        results.append(qMakePair(players[i], scores[i]));
    }

    // Сортируем по убыванию очков
    std::sort(results.begin(), results.end(),
              [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
                  return a.second > b.second;
              });

    return results;
}

QString ResultsWindow::getPlaceText(int place) const
{
    switch (place) {
    case 1: return "🥇 1-е место";
    case 2: return "🥈 2-е место";
    case 3: return "🥉 3-е место";
    default: return QString("🏅 %1-е место").arg(place);
    }
}

QString ResultsWindow::getPlaceStyle(int place) const
{
    switch (place) {
    case 1:
        return R"(
            QLabel {
                font-size: 22px;
                font-weight: bold;
                color: #ffd700;
                padding: 15px;
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                    stop:0 #ffd700, stop:0.3 #fffacd);
                border-radius: 10px;
                border: 3px solid #ffd700;
            }
        )";
    case 2:
        return R"(
            QLabel {
                font-size: 20px;
                font-weight: bold;
                color: #c0c0c0;
                padding: 15px;
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                    stop:0 #c0c0c0, stop:0.3 #f5f5f5);
                border-radius: 10px;
                border: 3px solid #c0c0c0;
            }
        )";
    case 3:
        return R"(
            QLabel {
                font-size: 18px;
                font-weight: bold;
                color: #cd7f32;
                padding: 15px;
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                    stop:0 #cd7f32, stop:0.3 #f4d3a1);
                border-radius: 10px;
                border: 3px solid #cd7f32;
            }
        )";
    default:
        return R"(
            QLabel {
                font-size: 16px;
                font-weight: bold;
                color: #3498db;
                padding: 15px;
                background-color: #16213e;
                border-radius: 10px;
                border: 2px solid #3498db;
            }
        )";
    }
}

void ResultsWindow::setupResultsTable(const QVector<QPair<QString, int>> &sortedResults)
{
    ui->tableWidget->setRowCount(sortedResults.size());
    ui->tableWidget->setColumnCount(3);  // Изменено с 4 на 3 (убрали столбец "Достижение")

    QStringList headers;
    headers << "Место" << "Игрок" << "Очки";  // Убрали "Достижение"
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Настройка таблицы
    ui->tableWidget->horizontalHeader()->setStyleSheet(R"(
        QHeaderView::section {
            background-color: #0f3460;
            color: white;
            font-weight: bold;
            font-size: 14px;
            padding: 10px;
            border: 1px solid #2d4059;
        }
    )");

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet(R"(
        QTableWidget {
            background-color: #16213e;
            color: white;
            font-size: 14px;
            border: 2px solid #2d4059;
            border-radius: 10px;
            gridline-color: #2d4059;
        }
        QTableWidget::item {
            padding: 15px;
            border-bottom: 1px solid #2d4059;
        }
        QTableWidget::item:selected {
            background-color: #3498db;
            color: white;
        }
        QScrollBar:vertical {
            border: none;
            background: #1a1a2e;
            width: 12px;
            border-radius: 6px;
        }
        QScrollBar::handle:vertical {
            background: #2d4059;
            border-radius: 6px;
            min-height: 30px;
        }
    )");

    // Заполняем таблицу
    for (int i = 0; i < sortedResults.size(); ++i) {
        int place = i + 1;
        const auto &player = sortedResults[i].first;
        int score = sortedResults[i].second;

        // Место
        QTableWidgetItem *placeItem = new QTableWidgetItem(getPlaceText(place));
        placeItem->setTextAlignment(Qt::AlignCenter);
        placeItem->setFlags(placeItem->flags() ^ Qt::ItemIsEditable);

        // Игрок
        QTableWidgetItem *playerItem = new QTableWidgetItem(player);
        playerItem->setTextAlignment(Qt::AlignCenter);
        playerItem->setFlags(playerItem->flags() ^ Qt::ItemIsEditable);

        // Очки
        QTableWidgetItem *scoreItem = new QTableWidgetItem(QString::number(score));
        scoreItem->setTextAlignment(Qt::AlignCenter);
        scoreItem->setFlags(scoreItem->flags() ^ Qt::ItemIsEditable);

        // Устанавливаем стили для строк
        QFont font;
        font.setBold(true);
        placeItem->setFont(font);

        if (place == 1) {
            placeItem->setForeground(QColor(255, 215, 0)); // Золотой
            playerItem->setForeground(QColor(255, 215, 0));
            scoreItem->setForeground(QColor(255, 215, 0));
        } else if (place == 2) {
            placeItem->setForeground(QColor(192, 192, 192)); // Серебряный
            playerItem->setForeground(QColor(192, 192, 192));
            scoreItem->setForeground(QColor(192, 192, 192));
        } else if (place == 3) {
            placeItem->setForeground(QColor(205, 127, 50)); // Бронзовый
            playerItem->setForeground(QColor(205, 127, 50));
            scoreItem->setForeground(QColor(205, 127, 50));
        }

        ui->tableWidget->setItem(i, 0, placeItem);
        ui->tableWidget->setItem(i, 1, playerItem);
        ui->tableWidget->setItem(i, 2, scoreItem);
    }

    // Ресайзим колонки
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Устанавливаем высоту строк
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        ui->tableWidget->setRowHeight(i, 60);
    }

    // Общая сумма очков
    int totalScore = 0;
    for (const auto &result : sortedResults) {
        totalScore += result.second;
    }
    ui->totalScoreLabel->setText(QString("Общая сумма очков: <span style='color:#ffd700; font-size: 18pt;'>%1</span>").arg(totalScore));

    // Победитель
    if (!sortedResults.isEmpty()) {
        QString winner = sortedResults[0].first;
        int winnerScore = sortedResults[0].second;
        ui->winnerLabel->setText(QString("Победитель: <span style='color:#ffd700; font-size: 20pt; font-weight: bold;'>%1</span> с <span style='color:#2ecc71; font-size: 18pt;'>%2 очками</span>!").arg(winner).arg(winnerScore));
    }
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::on_closeButton_clicked()
{
    emit returnToMainMenu();  // Испускаем сигнал
    this->accept();           // Закрываем окно результатов
}
