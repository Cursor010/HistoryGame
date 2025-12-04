#include "resultswindow.h"

#include <QCloseEvent>
#include <QDebug>
#include <QHeaderView>
#include <QTableWidgetItem>

#include <algorithm>

#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(const QStringList& players,
                             const QVector<int>& scores,
                             QWidget* parent)
    : QDialog(parent),
    ui_(new Ui::ResultsWindow) {
    ui_->setupUi(this);

    // Устанавливаем стиль окна
    this->setStyleSheet(
        "QDialog { background-color: #1a1a2e; font-family: 'Segoe UI', Arial, sans-serif; }");

    setWindowTitle("🏆 Результаты игры");
    setMinimumSize(800, 600);

    // Получаем отсортированные результаты
    QVector<QPair<QString, int>> sorted_results = GetSortedResults(players, scores);

    // Настраиваем таблицу результатов
    SetupResultsTable(sorted_results);

    // Подключаем кнопку закрытия
    connect(ui_->closeButton, &QPushButton::clicked, this,
            &ResultsWindow::on_closeButton_clicked);
}

ResultsWindow::~ResultsWindow() {
    delete ui_;
}

QVector<QPair<QString, int>> ResultsWindow::GetSortedResults(
    const QStringList& players, const QVector<int>& scores) const {
    QVector<QPair<QString, int>> results;

    // Собираем пары игрок-очки
    for (int i = 0; i < players.size(); ++i) {
        results.append(qMakePair(players[i], scores[i]));
    }

    // Сортируем по убыванию очков
    std::sort(results.begin(), results.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;
              });

    return results;
}

QString ResultsWindow::GetPlaceText(int place) const {
    switch (place) {
    case 1: return "🥇 1-е место";
    case 2: return "🥈 2-е место";
    case 3: return "🥉 3-е место";
    default: return QString("🏅 %1-е место").arg(place);
    }
}

QString ResultsWindow::GetPlaceStyle(int place) const {
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

void ResultsWindow::SetupResultsTable(
    const QVector<QPair<QString, int>>& sorted_results) {
    ui_->tableWidget->setRowCount(sorted_results.size());
    ui_->tableWidget->setColumnCount(3);  // Изменено с 4 на 3

    QStringList headers;
    headers << "Место" << "Игрок" << "Очки";  // Убрали "Достижение"
    ui_->tableWidget->setHorizontalHeaderLabels(headers);

    // Настройка таблицы
    ui_->tableWidget->horizontalHeader()->setStyleSheet(R"(
        QHeaderView::section {
            background-color: #0f3460;
            color: white;
            font-weight: bold;
            font-size: 14px;
            padding: 10px;
            border: 1px solid #2d4059;
        }
    )");

    ui_->tableWidget->verticalHeader()->setVisible(false);
    ui_->tableWidget->setShowGrid(false);
    ui_->tableWidget->setAlternatingRowColors(true);
    ui_->tableWidget->setStyleSheet(R"(
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
    for (int i = 0; i < sorted_results.size(); ++i) {
        int place = i + 1;
        const auto& player = sorted_results[i].first;
        int score = sorted_results[i].second;

        // Место
        QTableWidgetItem* place_item = new QTableWidgetItem(GetPlaceText(place));
        place_item->setTextAlignment(Qt::AlignCenter);
        place_item->setFlags(place_item->flags() ^ Qt::ItemIsEditable);

        // Игрок
        QTableWidgetItem* player_item = new QTableWidgetItem(player);
        player_item->setTextAlignment(Qt::AlignCenter);
        player_item->setFlags(player_item->flags() ^ Qt::ItemIsEditable);

        // Очки
        QTableWidgetItem* score_item = new QTableWidgetItem(QString::number(score));
        score_item->setTextAlignment(Qt::AlignCenter);
        score_item->setFlags(score_item->flags() ^ Qt::ItemIsEditable);

        // Устанавливаем стили для строк
        QFont font;
        font.setBold(true);
        place_item->setFont(font);

        if (place == 1) {
            place_item->setForeground(QColor(255, 215, 0));  // Золотой
            player_item->setForeground(QColor(255, 215, 0));
            score_item->setForeground(QColor(255, 215, 0));
        } else if (place == 2) {
            place_item->setForeground(QColor(192, 192, 192));  // Серебряный
            player_item->setForeground(QColor(192, 192, 192));
            score_item->setForeground(QColor(192, 192, 192));
        } else if (place == 3) {
            place_item->setForeground(QColor(205, 127, 50));  // Бронзовый
            player_item->setForeground(QColor(205, 127, 50));
            score_item->setForeground(QColor(205, 127, 50));
        }

        ui_->tableWidget->setItem(i, 0, place_item);
        ui_->tableWidget->setItem(i, 1, player_item);
        ui_->tableWidget->setItem(i, 2, score_item);
    }

    // Ресайзим колонки
    ui_->tableWidget->resizeColumnsToContents();
    ui_->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Устанавливаем высоту строк
    for (int i = 0; i < ui_->tableWidget->rowCount(); ++i) {
        ui_->tableWidget->setRowHeight(i, 60);
    }

    // Общая сумма очков
    int total_score = 0;
    for (const auto& result : sorted_results) {
        total_score += result.second;
    }
    ui_->totalScoreLabel->setText(
        QString("Общая сумма очков: <span style='color:#ffd700; font-size: 18pt;'>%1</span>")
            .arg(total_score));

    // Победитель
    if (!sorted_results.isEmpty()) {
        QString winner = sorted_results[0].first;
        int winner_score = sorted_results[0].second;
        ui_->winnerLabel->setText(
            QString("Победитель: <span style='color:#ffd700; font-size: 20pt; "
                    "font-weight: bold;'>%1</span> с <span style='color:#2ecc71; "
                    "font-size: 18pt;'>%2 очками</span>!")
                .arg(winner)
                .arg(winner_score));
    }
}

void ResultsWindow::on_closeButton_clicked() {
    emit returnToMainMenu();
    this->close();  // Используем close() вместо accept()
}

void ResultsWindow::closeEvent(QCloseEvent* event) {
    // Не испускаем сигнал здесь, чтобы не дублировать
    event->accept();
}
