#include "gamewindow.h"
#include "questionwindow.h"
#include "resultswindow.h"
#include "mainwindow.h"

#include <QCloseEvent>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTimer>
#include <QXmlStreamReader>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QFont>
#include <QScrollArea>
#include <QScrollBar>

#include "ui_gamewindow.h"

GameWindow::GameWindow(const QStringList& players, QWidget* parent)
    : QMainWindow(parent),
    ui_(new Ui::GameWindow),
    players_(players),
    current_player_(0),
    current_question_button_(nullptr),
    total_questions_(25),
    answered_questions_(0) {
    ui_->setupUi(this);

    scores_.resize(players_.size());
    for (int i = 0; i < scores_.size(); ++i) {
        scores_[i] = 0;
    }

    // Пытаемся загрузить вопросы из XML
    if (!LoadQuestionsFromXml()) {
        qDebug() << "Используются стандартные вопросы";
        CreateQuestions();
    }

    SetupGame();
}

GameWindow::~GameWindow() {
    delete ui_;
}

bool GameWindow::LoadQuestionsFromXml() {
    QStringList possible_paths = {
        "questions.xml",
        QDir::currentPath() + "/questions.xml",
        QApplication::applicationDirPath() + "/questions.xml",
    };

    QFile file;
    for (const QString& path : possible_paths) {
        file.setFileName(path);
        if (file.exists()) {
            qDebug() << "Найден файл вопросов:" << path;
            break;
        }
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл questions.xml";
        return false;
    }

    QXmlStreamReader xml(&file);

    questions_.clear();
    questions_.resize(5);
    for (int i = 0; i < 5; ++i) {
        questions_[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            questions_[i][j].value = (j + 1) * 100;
            questions_[i][j].answered = false;
            questions_[i][j].question = "Вопрос не загружен";
            questions_[i][j].answer = "Ответ не загружен";
        }
    }

    int current_theme = -1;
    int current_value = 0;
    QString current_text;
    QString current_element;

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement) {
            QString element_name = xml.name().toString();

            if (element_name == "theme") {
                current_theme++;
            } else if (element_name == "question") {
                current_value = xml.attributes().value("value").toInt();
            } else if (element_name == "text" || element_name == "answer") {
                current_element = element_name;
                current_text.clear();
            }
        } else if (token == QXmlStreamReader::Characters) {
            if (!xml.isWhitespace()) {
                current_text += xml.text().toString();
            }
        } else if (token == QXmlStreamReader::EndElement) {
            QString element_name = xml.name().toString();

            if (element_name == "text" && current_theme >= 0 && current_theme < 5) {
                int value_index = current_value / 100 - 1;
                if (value_index >= 0 && value_index < 5) {
                    questions_[current_theme][value_index].question = current_text.trimmed();
                }
            } else if (element_name == "answer" && current_theme >= 0 && current_theme < 5) {
                int value_index = current_value / 100 - 1;
                if (value_index >= 0 && value_index < 5) {
                    questions_[current_theme][value_index].answer = current_text.trimmed();
                }
            }
        }
    }

    if (xml.hasError()) {
        qDebug() << "Ошибка XML:" << xml.errorString();
        file.close();
        return false;
    }

    file.close();

    // Проверяем загрузку
    bool success = true;
    int loaded_count = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (questions_[i][j].question != "Вопрос не загружен" &&
                questions_[i][j].answer != "Ответ не загружен") {
                loaded_count++;
            } else {
                success = false;
            }
        }
    }

    if (success) {
        qDebug() << "Все" << loaded_count << "вопросов успешно загружены из XML";
    } else {
        qDebug() << "Загружено" << loaded_count << "вопросов из 25";
    }

    return success;
}

void GameWindow::CreateQuestions() {
    QStringList themes = {"Термины", "Личности", "Даты", "Политические партии", "Лозунги"};
    questions_.resize(5);

    for (int i = 0; i < 5; ++i) {
        questions_[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            questions_[i][j].question = QString("Стандартный вопрос по теме '%1' стоимостью %2")
                                            .arg(themes[i])
                                            .arg((j + 1) * 100);
            questions_[i][j].answer = QString("Стандартный ответ на вопрос стоимостью %1").arg((j + 1) * 100);
            questions_[i][j].value = (j + 1) * 100;
            questions_[i][j].answered = false;
        }
    }
}

void GameWindow::SetupGame() {
    // Настраиваем кнопки вопросов
    QList<QPushButton*> theme1_buttons = {
        ui_->theme1_100, ui_->theme1_200, ui_->theme1_300, ui_->theme1_400, ui_->theme1_500
    };
    QList<QPushButton*> theme2_buttons = {
        ui_->theme2_100, ui_->theme2_200, ui_->theme2_300, ui_->theme2_400, ui_->theme2_500
    };
    QList<QPushButton*> theme3_buttons = {
        ui_->theme3_100, ui_->theme3_200, ui_->theme3_300, ui_->theme3_400, ui_->theme3_500
    };
    QList<QPushButton*> theme4_buttons = {
        ui_->theme4_100, ui_->theme4_200, ui_->theme4_300, ui_->theme4_400, ui_->theme4_500
    };
    QList<QPushButton*> theme5_buttons = {
        ui_->theme5_100, ui_->theme5_200, ui_->theme5_300, ui_->theme5_400, ui_->theme5_500
    };

    QList<QList<QPushButton*>> all_buttons = {
        theme1_buttons, theme2_buttons, theme3_buttons, theme4_buttons, theme5_buttons
    };

    for (int theme = 0; theme < all_buttons.size(); ++theme) {
        for (int value_index = 0; value_index < all_buttons[theme].size(); ++value_index) {
            QPushButton* button = all_buttons[theme][value_index];
            button->setProperty("theme", theme);
            button->setProperty("valueIndex", value_index);
            connect(button, &QPushButton::clicked, this, &GameWindow::handleQuestionClick);
        }
    }

    // Создаем скроллинг для панели игроков
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Настраиваем стиль скроллбара
    scrollArea->setStyleSheet(R"(
        QScrollArea {
            border: none;
            background: transparent;
        }
        QScrollBar:vertical {
            background: #34495e;
            width: 10px;
            border-radius: 5px;
        }
        QScrollBar::handle:vertical {
            background: #7f8c8d;
            border-radius: 5px;
            min-height: 20px;
        }
        QScrollBar::handle:vertical:hover {
            background: #95a5a6;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }
    )");

    // Создаем виджет для содержимого скроллинга
    QWidget* scrollContent = new QWidget();
    players_container_layout_ = new QVBoxLayout(scrollContent);
    players_container_layout_->setSpacing(8);
    players_container_layout_->setContentsMargins(5, 5, 5, 5);
    players_container_layout_->setAlignment(Qt::AlignTop);

    scrollArea->setWidget(scrollContent);

    // Очищаем старый layout и добавляем скролл
    QLayoutItem* child;
    while ((child = ui_->playersPanelLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    ui_->playersPanelLayout->addWidget(scrollArea);

    UpdatePlayersPanel();
    UpdateScore();
}

void GameWindow::UpdatePlayersPanel() {
    // Очищаем старые виджеты
    player_frames_.clear();

    if (!players_container_layout_) return;

    QLayoutItem* item;
    while ((item = players_container_layout_->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Создаем виджеты для каждого игрока
    for (int i = 0; i < players_.size(); ++i) {
        QFrame* playerFrame = new QFrame();
        playerFrame->setObjectName(QString("playerFrame_%1").arg(i));
        playerFrame->setMinimumHeight(70);
        playerFrame->setMaximumHeight(70);
        playerFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        if (i == current_player_) {
            playerFrame->setStyleSheet(R"(
                QFrame {
                    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                        stop:0 #1abc9c, stop:1 #16a085);
                    border-radius: 10px;
                    border: 3px solid #27ae60;
                    padding: 5px;
                }
            )");
        } else {
            playerFrame->setStyleSheet(R"(
                QFrame {
                    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                        stop:0 #34495e, stop:1 #2c3e50);
                    border-radius: 10px;
                    border: 2px solid #2d4059;
                    padding: 5px;
                }
            )");
        }

        QHBoxLayout* frameLayout = new QHBoxLayout(playerFrame);
        frameLayout->setContentsMargins(10, 5, 10, 5);
        frameLayout->setSpacing(15);

        // Номер игрока с иконкой
        QLabel* playerIcon = new QLabel();
        playerIcon->setText(QString("🎮 %1").arg(i + 1));
        playerIcon->setStyleSheet(R"(
            QLabel {
                font-size: 14pt;
                font-weight: bold;
                color: #ecf0f1;
                min-width: 30px;
            }
        )");

        // Имя игрока
        QLabel* playerName = new QLabel(players_[i]);
        QFont nameFont("Segoe UI", 12, QFont::Bold);
        playerName->setFont(nameFont);
        playerName->setStyleSheet(R"(
            QLabel {
                color: #ecf0f1;
                min-width: 120px;
            }
        )");

        // Счет игрока
        QLabel* playerScore = new QLabel(QString::number(scores_[i]));
        QFont scoreFont("Segoe UI", 14, QFont::Bold);
        playerScore->setFont(scoreFont);
        playerScore->setStyleSheet(R"(
            QLabel {
                color: #f1c40f;
                background: rgba(0, 0, 0, 30%);
                border-radius: 5px;
                padding: 5px 10px;
                min-width: 60px;
                text-align: center;
            }
        )");

        // Индикатор текущего хода (только для активного игрока)
        if (i == current_player_) {
            QLabel* turnIndicator = new QLabel("▶");
            turnIndicator->setStyleSheet(R"(
                QLabel {
                    font-size: 16pt;
                    color: #e74c3c;
                    font-weight: bold;
                }
            )");
            frameLayout->addWidget(turnIndicator);
        } else {
            QLabel* emptyIndicator = new QLabel();
            emptyIndicator->setFixedWidth(20);
            frameLayout->addWidget(emptyIndicator);
        }

        frameLayout->addWidget(playerIcon);
        frameLayout->addWidget(playerName);
        frameLayout->addStretch();
        frameLayout->addWidget(playerScore);

        players_container_layout_->addWidget(playerFrame);
        player_frames_.append(playerFrame);
    }

    // Добавляем растягивающийся спейсер в конец
    players_container_layout_->addStretch();

    // Прокручиваем к текущему игроку
    QTimer::singleShot(100, this, &GameWindow::ScrollToCurrentPlayer);
}

void GameWindow::ScrollToCurrentPlayer() {
    if (current_player_ < player_frames_.size()) {
        QFrame* currentFrame = player_frames_[current_player_];

        // Находим родительский QScrollArea
        QWidget* parent = currentFrame->parentWidget();
        while (parent && !qobject_cast<QScrollArea*>(parent)) {
            parent = parent->parentWidget();
        }

        if (QScrollArea* scrollArea = qobject_cast<QScrollArea*>(parent)) {
            // Прокручиваем к текущему игроку
            scrollArea->ensureWidgetVisible(currentFrame, 0, 50);
        }
    }
}

void GameWindow::handleQuestionClick() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int theme = button->property("theme").toInt();
    int value_index = button->property("valueIndex").toInt();

    if (questions_[theme][value_index].answered) {
        return;
    }

    current_question_button_ = button;

    QuestionWindow* question_window = new QuestionWindow(
        questions_[theme][value_index].question,
        questions_[theme][value_index].answer, questions_[theme][value_index].value,
        this);

    connect(question_window, &QuestionWindow::answerResult, this,
            &GameWindow::handleAnswerResult);
    question_window->exec();
}

void GameWindow::handleAnswerResult(bool correct) {
    if (!current_question_button_) {
        return;
    }

    int theme = current_question_button_->property("theme").toInt();
    int value_index = current_question_button_->property("valueIndex").toInt();

    questions_[theme][value_index].answered = true;
    current_question_button_->setEnabled(false);
    answered_questions_++;

    // Делаем кнопку серой
    current_question_button_->setStyleSheet(R"(
        QPushButton {
            background: #7f8c8d;
            color: #bdc3c7;
            font-size: 20pt;
            font-weight: bold;
            padding: 15px;
            border: 2px solid #636e72;
            border-radius: 10px;
        }
    )");

    if (correct) {
        scores_[current_player_] += questions_[theme][value_index].value;
    }

    NextTurn();
    current_question_button_ = nullptr;

    // Проверяем, все ли вопросы отвечены
    CheckIfAllQuestionsAnswered();
}

void GameWindow::CheckIfAllQuestionsAnswered() {
    if (answered_questions_ >= total_questions_) {
        qDebug() << "Все вопросы отвечены!";
        QTimer::singleShot(1000, this, &GameWindow::AutoFinishGame);
    }
}

void GameWindow::AutoFinishGame() {
    qDebug() << "Автоматическое завершение игры...";

    // Отключаем все кнопки вопросов
    DisableAllQuestionButtons();

    // Отключаем кнопку завершения игры
    ui_->endGameButton->setEnabled(false);

    // Показываем окно результатов
    ResultsWindow* results_window = new ResultsWindow(players_, scores_, nullptr);

    // Подключаем сигнал возврата к главному меню
    connect(results_window, &ResultsWindow::returnToMainMenu, this,
            &GameWindow::onReturnToMainMenu);

    // Устанавливаем флаг для автоматического удаления при закрытии
    results_window->setAttribute(Qt::WA_DeleteOnClose);
    results_window->show();
}

void GameWindow::NextTurn() {
    current_player_ = (current_player_ + 1) % players_.size();
    UpdateScore();
    UpdatePlayersPanel();
}

void GameWindow::UpdateScore() {
    ui_->currentPlayerLabel->setText("Текущий игрок: " + players_[current_player_]);
    ui_->scoreLabel->setText("Счет: " + QString::number(scores_[current_player_]));
}

void GameWindow::on_endGameButton_clicked() {
    qDebug() << "Завершение игры...";

    // Отключаем все кнопки вопросов
    DisableAllQuestionButtons();

    // Отключаем кнопку завершения игры
    ui_->endGameButton->setEnabled(false);

    // Показываем окно результатов
    ResultsWindow* results_window = new ResultsWindow(players_, scores_, nullptr);

    // Подключаем сигнал возврата к главному меню
    connect(results_window, &ResultsWindow::returnToMainMenu, this,
            &GameWindow::onReturnToMainMenu);

    // Устанавливаем флаг для автоматического удаления при закрытии
    results_window->setAttribute(Qt::WA_DeleteOnClose);
    results_window->show();
}

void GameWindow::DisableAllQuestionButtons() {
    // Список всех кнопок вопросов
    QList<QPushButton*> all_buttons = {
                                        ui_->theme1_100, ui_->theme1_200, ui_->theme1_300, ui_->theme1_400,
                                        ui_->theme1_500, ui_->theme2_100, ui_->theme2_200, ui_->theme2_300,
                                        ui_->theme2_400, ui_->theme2_500, ui_->theme3_100, ui_->theme3_200,
                                        ui_->theme3_300, ui_->theme3_400, ui_->theme3_500, ui_->theme4_100,
                                        ui_->theme4_200, ui_->theme4_300, ui_->theme4_400, ui_->theme4_500,
                                        ui_->theme5_100, ui_->theme5_200, ui_->theme5_300, ui_->theme5_400,
                                        ui_->theme5_500};

    // Отключаем все кнопки
    for (QPushButton* button : all_buttons) {
        button->setEnabled(false);
        button->setStyleSheet(R"(
        QPushButton {
            background: #7f8c8d;
            color: #bdc3c7;
            font-size: 20pt;
            font-weight: bold;
            padding: 15px;
            border: 2px solid #636e72;
            border-radius: 10px;
        }
    )");
    }
}

void GameWindow::onReturnToMainMenu() {
    // Проверяем, не создано ли уже главное окно
    if (main_window_) {
        return;
    }

    main_window_ = new MainWindow();
    main_window_->show();
    this->close();

    // Удаляем текущее окно игры через таймер
    QTimer::singleShot(100, this, &QWidget::deleteLater);
}
