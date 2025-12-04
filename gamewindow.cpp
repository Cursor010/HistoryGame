#include "gamewindow.h"

#include <QCloseEvent>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTimer>
#include <QXmlStreamReader>

#include "questionwindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(const QStringList& players, QWidget* parent)
    : QMainWindow(parent),
    ui_(new Ui::GameWindow),
    players_(players),
    current_player_(0),
    current_question_button_(nullptr) {
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
    // Проверяем несколько возможных путей к файлу
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
        qDebug() << "Текущая директория:" << QDir::currentPath();
        qDebug() << "Директория приложения:" << QApplication::applicationDirPath();
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
                qDebug() << "Начата тема:" << current_theme;
            } else if (element_name == "question") {
                current_value = xml.attributes().value("value").toInt();
                qDebug() << "Найден вопрос стоимостью:" << current_value;
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
                    questions_[current_theme][value_index].question =
                        current_text.trimmed();
                    qDebug() << "Загружен вопрос: тема" << current_theme << "стоимость"
                             << current_value << ":" << current_text.left(50) + "...";
                }
            } else if (element_name == "answer" && current_theme >= 0 &&
                       current_theme < 5) {
                int value_index = current_value / 100 - 1;
                if (value_index >= 0 && value_index < 5) {
                    questions_[current_theme][value_index].answer = current_text.trimmed();
                    qDebug() << "Загружен ответ: тема" << current_theme << "стоимость"
                             << current_value;
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
                qDebug() << "Не загружен вопрос: тема" << i << "стоимость"
                         << ((j + 1) * 100);
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
    QStringList themes = {"Термины", "Личности", "Даты", "Политические партии",
                          "Лозунги"};
    questions_.resize(5);

    for (int i = 0; i < 5; ++i) {
        questions_[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            questions_[i][j].question =
                QString("Стандартный вопрос по теме '%1' стоимостью %2")
                    .arg(themes[i])
                    .arg((j + 1) * 100);
            questions_[i][j].answer =
                QString("Стандартный ответ на вопрос стоимостью %1").arg((j + 1) * 100);
            questions_[i][j].value = (j + 1) * 100;
            questions_[i][j].answered = false;
        }
    }
}

void GameWindow::SetupGame() {
    // Настраиваем кнопки вопросов
    QList<QPushButton*> theme1_buttons = {
                                           ui_->theme1_100, ui_->theme1_200, ui_->theme1_300, ui_->theme1_400,
                                           ui_->theme1_500};
    QList<QPushButton*> theme2_buttons = {
                                           ui_->theme2_100, ui_->theme2_200, ui_->theme2_300, ui_->theme2_400,
                                           ui_->theme2_500};
    QList<QPushButton*> theme3_buttons = {
                                           ui_->theme3_100, ui_->theme3_200, ui_->theme3_300, ui_->theme3_400,
                                           ui_->theme3_500};
    QList<QPushButton*> theme4_buttons = {
                                           ui_->theme4_100, ui_->theme4_200, ui_->theme4_300, ui_->theme4_400,
                                           ui_->theme4_500};
    QList<QPushButton*> theme5_buttons = {
                                           ui_->theme5_100, ui_->theme5_200, ui_->theme5_300, ui_->theme5_400,
                                           ui_->theme5_500};

    QList<QList<QPushButton*>> all_buttons = {
                                               theme1_buttons, theme2_buttons, theme3_buttons, theme4_buttons,
                                               theme5_buttons};

    for (int theme = 0; theme < all_buttons.size(); ++theme) {
        for (int value_index = 0; value_index < all_buttons[theme].size();
             ++value_index) {
            QPushButton* button = all_buttons[theme][value_index];
            button->setProperty("theme", theme);
            button->setProperty("valueIndex", value_index);
            connect(button, &QPushButton::clicked, this,
                    &GameWindow::handleQuestionClick);
        }
    }

    UpdateScore();
}

void GameWindow::handleQuestionClick() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int theme = button->property("theme").toInt();
    int value_index = button->property("valueIndex").toInt();

    if (questions_[theme][value_index].answered) {
        return;
    }

    current_question_button_ = button;

    qDebug() << "=== ОТКРЫВАЕМ ВОПРОС ===";
    qDebug() << "Тема:" << theme << "Стоимость:" << ((value_index + 1) * 100);
    qDebug() << "Вопрос:" << questions_[theme][value_index].question;
    qDebug() << "Ответ:" << questions_[theme][value_index].answer;

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
}

void GameWindow::NextTurn() {
    current_player_ = (current_player_ + 1) % players_.size();
    UpdateScore();
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
