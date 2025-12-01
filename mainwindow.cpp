#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QFrame>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    savedPlayerNames.clear();
    setupPlayersLayout();

    // Устанавливаем курсор после первого символа в QSpinBox
    QTimer::singleShot(0, this, [this]() {
        QLineEdit *spinBoxLineEdit = ui->playerCountSpinBox->findChild<QLineEdit*>();
        if (spinBoxLineEdit) {
            spinBoxLineEdit->setCursorPosition(1); // После первого символа
        }
    });
}

void MainWindow::setupPlayersLayout()
{
    // Сохраняем текущие имена игроков перед очисткой
    QStringList currentNames;
    for (QLineEdit *input : playerInputs) {
        QString name = input->text().trimmed();
        if (name.isEmpty() || name.startsWith("Игрок ")) {
            currentNames.append(""); // Пустое имя для дефолтных значений
        } else {
            currentNames.append(name);
        }
    }

    // Сохраняем имена, но только если у нас уже есть сохраненные имена
    // или мы в процессе первого запуска
    if (savedPlayerNames.isEmpty() || !currentNames.isEmpty()) {
        savedPlayerNames = currentNames;
    }

    // Очищаем старые поля ввода и layouts
    for (QLineEdit *input : playerInputs) {
        input->deleteLater();
    }
    playerInputs.clear();

    for (QHBoxLayout *layout : playerLayouts) {
        // Удаляем все виджеты из layout
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
        delete layout;
    }
    playerLayouts.clear();

    int playerCount = ui->playerCountSpinBox->value();

    for (int i = 0; i < playerCount; ++i) {
        QHBoxLayout *playerLayout = new QHBoxLayout();
        playerLayout->setSpacing(15);

        // Создаем контейнер для номера игрока
        QFrame *numberFrame = new QFrame();
        numberFrame->setFixedSize(40, 40);
        numberFrame->setStyleSheet(R"(
            QFrame {
                background-color: #3498db;
                border-radius: 5px;
                border: 2px solid #2980b9;
            }
        )");

        QLabel *numberLabel = new QLabel(QString::number(i + 1));
        numberLabel->setAlignment(Qt::AlignCenter);
        numberLabel->setStyleSheet(R"(
            QLabel {
                color: white;
                font-size: 16px;
                font-weight: bold;
                background: transparent;
            }
        )");

        QVBoxLayout *numberLayout = new QVBoxLayout(numberFrame);
        numberLayout->addWidget(numberLabel);
        numberLayout->setContentsMargins(0, 0, 0, 0);

        // Поле ввода для имени игрока
        // Проверяем, есть ли сохраненное имя для этого индекса
        QString defaultName;
        if (i < savedPlayerNames.size() && !savedPlayerNames[i].isEmpty()) {
            // Используем сохраненное имя
            defaultName = savedPlayerNames[i];
        } else {
            // Используем имя по умолчанию
            defaultName = QString("Игрок %1").arg(i + 1);
        }

        QLineEdit *playerInput = new QLineEdit(defaultName);
        playerInput->setStyleSheet(R"(
            QLineEdit {
                border: 2px solid #7f8c8d;
                border-radius: 8px;
                padding: 10px;
                font-size: 14px;
                background-color: #2c3e50;
                color: #ecf0f1;
                selection-background-color: #3498db;
                selection-color: white;
            }
            QLineEdit:focus {
                border-color: #3498db;
                background-color: #34495e;
            }
            QLineEdit:hover {
                border-color: #95a5a6;
            }
            QLineEdit:disabled {
                background-color: #4a6278;
                color: #bdc3c7;
            }
        )");
        playerInput->setMinimumHeight(40);

        // Устанавливаем курсор после первого символа
        QTimer::singleShot(0, [playerInput]() {
            QString text = playerInput->text();
            if (!text.isEmpty()) {
                playerInput->setCursorPosition(1);
            }
        });

        // Добавляем элементы в layout
        playerLayout->addWidget(numberFrame);
        playerLayout->addWidget(playerInput, 1); // 1 означает растягивание

        // Добавляем layout в основной
        ui->playersLayout->insertLayout(ui->playersLayout->count() - 1, playerLayout);

        playerInputs.append(playerInput);
        playerLayouts.append(playerLayout);
    }
}

void MainWindow::on_playerCountSpinBox_valueChanged(int arg1)
{
    // Сохраняем текущие имена перед обновлением
    savedPlayerNames.clear();
    for (QLineEdit *input : playerInputs) {
        QString name = input->text().trimmed();
        savedPlayerNames.append(name);
    }

    setupPlayersLayout();
}

void MainWindow::on_startGameButton_clicked()
{
    QStringList playerNames;
    for (QLineEdit *input : playerInputs) {
        QString name = input->text().trimmed();
        if (!name.isEmpty()) {
            playerNames.append(name);
        } else {
            playerNames.append("Игрок");
        }
    }

    if (playerNames.isEmpty()) {
        playerNames.append("Игрок 1");
    }

    GameWindow *gameWindow = new GameWindow(playerNames);
    gameWindow->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
