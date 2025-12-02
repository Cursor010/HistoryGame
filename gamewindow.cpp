#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "questionwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QDir>

GameWindow::GameWindow(const QStringList &players, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , players(players)
    , currentPlayer(0)
    , currentQuestionButton(nullptr)
{
    ui->setupUi(this);

    scores.resize(players.size());
    for(int i = 0; i < scores.size(); ++i) {
        scores[i] = 0;
    }

    // Пытаемся загрузить вопросы из XML, если не получается - создаем стандартные
    if (!loadQuestionsFromXML()) {
        qDebug() << "Используются стандартные вопросы";
        createQuestions();
    }

    setupGame();
}

bool GameWindow::loadQuestionsFromXML()
{
    // Проверяем несколько возможных путей к файлу
    QStringList possiblePaths = {
        "questions.xml",
        QDir::currentPath() + "/questions.xml",
        QApplication::applicationDirPath() + "/questions.xml"
    };

    QFile file;
    for (const QString &path : possiblePaths) {
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

    questions.clear();
    questions.resize(5);
    for (int i = 0; i < 5; ++i) {
        questions[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            questions[i][j].value = (j + 1) * 100;
            questions[i][j].answered = false;
            questions[i][j].question = "Вопрос не загружен";
            questions[i][j].answer = "Ответ не загружен";
        }
    }

    int currentTheme = -1;
    int currentValue = 0;
    QString currentText;
    QString currentElement;

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement) {
            QString elementName = xml.name().toString();

            if (elementName == "theme") {
                currentTheme++;
                qDebug() << "Начата тема:" << currentTheme;
            }
            else if (elementName == "question") {
                currentValue = xml.attributes().value("value").toInt();
                qDebug() << "Найден вопрос стоимостью:" << currentValue;
            }
            else if (elementName == "text" || elementName == "answer") {
                currentElement = elementName;
                currentText.clear();
            }
        }
        else if (token == QXmlStreamReader::Characters) {
            if (!xml.isWhitespace()) {
                currentText += xml.text().toString();
            }
        }
        else if (token == QXmlStreamReader::EndElement) {
            QString elementName = xml.name().toString();

            if (elementName == "text" && currentTheme >= 0 && currentTheme < 5) {
                int valueIndex = currentValue / 100 - 1;
                if (valueIndex >= 0 && valueIndex < 5) {
                    questions[currentTheme][valueIndex].question = currentText.trimmed();
                    qDebug() << "Загружен вопрос: тема" << currentTheme << "стоимость" << currentValue << ":" << currentText.left(50) + "...";
                }
            }
            else if (elementName == "answer" && currentTheme >= 0 && currentTheme < 5) {
                int valueIndex = currentValue / 100 - 1;
                if (valueIndex >= 0 && valueIndex < 5) {
                    questions[currentTheme][valueIndex].answer = currentText.trimmed();
                    qDebug() << "Загружен ответ: тема" << currentTheme << "стоимость" << currentValue;
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
    int loadedCount = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (questions[i][j].question != "Вопрос не загружен" &&
                questions[i][j].answer != "Ответ не загружен") {
                loadedCount++;
            } else {
                success = false;
                qDebug() << "Не загружен вопрос: тема" << i << "стоимость" << ((j+1)*100);
            }
        }
    }

    if (success) {
        qDebug() << "Все" << loadedCount << "вопросов успешно загружены из XML";
    } else {
        qDebug() << "Загружено" << loadedCount << "вопросов из 25";
    }

    return success;
}

void GameWindow::createQuestions()
{
    QStringList themes = {"Термины", "Личности", "Даты", "Политические партии", "Лозунги"};
    questions.resize(5);

    for(int i = 0; i < 5; ++i) {
        questions[i].resize(5);
        for(int j = 0; j < 5; ++j) {
            questions[i][j].question = QString("Стандартный вопрос по теме '%1' стоимостью %2")
                                           .arg(themes[i]).arg((j+1)*100);
            questions[i][j].answer = QString("Стандартный ответ на вопрос стоимостью %1").arg((j+1)*100);
            questions[i][j].value = (j+1)*100;
            questions[i][j].answered = false;
        }
    }
}

void GameWindow::setupGame()
{
    // Настраиваем кнопки вопросов
    QList<QPushButton*> theme1Buttons = {ui->theme1_100, ui->theme1_200, ui->theme1_300, ui->theme1_400, ui->theme1_500};
    QList<QPushButton*> theme2Buttons = {ui->theme2_100, ui->theme2_200, ui->theme2_300, ui->theme2_400, ui->theme2_500};
    QList<QPushButton*> theme3Buttons = {ui->theme3_100, ui->theme3_200, ui->theme3_300, ui->theme3_400, ui->theme3_500};
    QList<QPushButton*> theme4Buttons = {ui->theme4_100, ui->theme4_200, ui->theme4_300, ui->theme4_400, ui->theme4_500};
    QList<QPushButton*> theme5Buttons = {ui->theme5_100, ui->theme5_200, ui->theme5_300, ui->theme5_400, ui->theme5_500};

    QList<QList<QPushButton*>> allButtons = {theme1Buttons, theme2Buttons, theme3Buttons, theme4Buttons, theme5Buttons};

    for(int theme = 0; theme < allButtons.size(); theme++) {
        for(int valueIndex = 0; valueIndex < allButtons[theme].size(); valueIndex++) {
            QPushButton *button = allButtons[theme][valueIndex];
            button->setProperty("theme", theme);
            button->setProperty("valueIndex", valueIndex);
            connect(button, &QPushButton::clicked, this, &GameWindow::handleQuestionClick);
        }
    }

    updateScore();
}

void GameWindow::handleQuestionClick()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    int theme = button->property("theme").toInt();
    int valueIndex = button->property("valueIndex").toInt();

    if(questions[theme][valueIndex].answered) {
        return;
    }

    currentQuestionButton = button;

    qDebug() << "=== ОТКРЫВАЕМ ВОПРОС ===";
    qDebug() << "Тема:" << theme << "Стоимость:" << ((valueIndex+1)*100);
    qDebug() << "Вопрос:" << questions[theme][valueIndex].question;
    qDebug() << "Ответ:" << questions[theme][valueIndex].answer;

    QuestionWindow *questionWindow = new QuestionWindow(
        questions[theme][valueIndex].question,
        questions[theme][valueIndex].answer,
        questions[theme][valueIndex].value,
        this
        );

    connect(questionWindow, &QuestionWindow::answerResult, this, &GameWindow::handleAnswerResult);
    questionWindow->exec();
}

void GameWindow::handleAnswerResult(bool correct)
{
    if (!currentQuestionButton) {
        return;
    }

    int theme = currentQuestionButton->property("theme").toInt();
    int valueIndex = currentQuestionButton->property("valueIndex").toInt();

    questions[theme][valueIndex].answered = true;
    currentQuestionButton->setEnabled(false);

    // Делаем кнопку серой
    currentQuestionButton->setStyleSheet(R"(
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

    if(correct) scores[currentPlayer] += questions[theme][valueIndex].value;

    nextTurn();
    currentQuestionButton = nullptr;
}

void GameWindow::nextTurn()
{
    currentPlayer = (currentPlayer + 1) % players.size();
    updateScore();
}

void GameWindow::updateScore()
{
    ui->currentPlayerLabel->setText("Текущий игрок: " + players[currentPlayer]);
    ui->scoreLabel->setText("Счет: " + QString::number(scores[currentPlayer]));
}

void GameWindow::on_endGameButton_clicked()
{
    qDebug() << "Завершение игры...";

    // Отключаем все кнопки вопросов
    disableAllQuestionButtons();

    // Отключаем кнопку завершения игры
    ui->endGameButton->setEnabled(false);
    ui->endGameButton->setStyleSheet(R"(
        QPushButton {
            background: #7f8c8d;
            color: #bdc3c7;
            font-size: 18px;
            font-weight: bold;
            border: none;
            border-radius: 10px;
            padding: 15px 30px;
        }
    )");

    // Показываем окно результатов
    ResultsWindow *resultsWindow = new ResultsWindow(players, scores, this);
    resultsWindow->exec();
}

void GameWindow::disableAllQuestionButtons()
{
    // Список всех кнопок вопросов
    QList<QPushButton*> allButtons = {
        ui->theme1_100, ui->theme1_200, ui->theme1_300, ui->theme1_400, ui->theme1_500,
        ui->theme2_100, ui->theme2_200, ui->theme2_300, ui->theme2_400, ui->theme2_500,
        ui->theme3_100, ui->theme3_200, ui->theme3_300, ui->theme3_400, ui->theme3_500,
        ui->theme4_100, ui->theme4_200, ui->theme4_300, ui->theme4_400, ui->theme4_500,
        ui->theme5_100, ui->theme5_200, ui->theme5_300, ui->theme5_400, ui->theme5_500
    };

    // Отключаем все кнопки
    for (QPushButton *button : allButtons) {
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

GameWindow::~GameWindow()
{
    delete ui;
}
