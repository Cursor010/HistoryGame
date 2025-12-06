#include "questionparser.h"

#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>

QuestionParser::QuestionParser()
    : loaded_count_(0), success_(false) {}

bool QuestionParser::LoadFromResource(QVector<QVector<Question>>& questions) {
    QString resourcePath = ":/assets/data/questions.xml";
    qDebug() << "Попытка открыть ресурс:" << resourcePath;

    QFile resourceFile(resourcePath);
    if (!resourceFile.exists()) {
        qDebug() << "ОШИБКА: Ресурс не существует:" << resourcePath;
        qDebug() << "Проверьте файл resources.qrc и путь к XML файлу";
        return false;
    }

    if (!resourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ОШИБКА: Не удалось открыть ресурс:" << resourcePath;
        return false;
    }

    // Читаем XML из ресурса
    QByteArray xmlData = resourceFile.readAll();
    resourceFile.close();

    qDebug() << "Успешно прочитано" << xmlData.size() << "байт из ресурса";

    if (xmlData.isEmpty()) {
        qDebug() << "ОШИБКА: Ресурс пустой";
        return false;
    }

    // Парсим XML
    if (!ParseXmlFromByteArray(xmlData, questions)) {
        qDebug() << "ОШИБКА: Не удалось распарсить XML";
        return false;
    }

    // Проверяем, что все вопросы загружены
    if (CheckLoadedQuestions(questions)) {
        qDebug() << "=== УСПЕХ: Все" << loaded_count_ << "вопросов загружены из ресурсов ===";
        return true;
    } else {
        qDebug() << "=== ЧАСТИЧНЫЙ УСПЕХ: Загружено" << loaded_count_ << "вопросов из 25 ===";
        return true;  // Возвращаем true даже если не все вопросы загружены
    }
}

bool QuestionParser::ParseXmlFromByteArray(const QByteArray& xmlData,
                                           QVector<QVector<Question>>& questions) {
    InitializeQuestions(questions);

    QXmlStreamReader xml(xmlData);
    int current_theme = -1;
    int current_value = 0;
    QString current_text;
    bool insideText = false;
    bool insideAnswer = false;

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement) {
            QString element_name = xml.name().toString();

            if (element_name == "theme") {
                current_theme++;
                qDebug() << "Найдена тема" << current_theme;
            } else if (element_name == "question") {
                current_value = xml.attributes().value("value").toInt();
            } else if (element_name == "text") {
                insideText = true;
                current_text.clear();
            } else if (element_name == "answer") {
                insideAnswer = true;
                current_text.clear();
            }
        } else if (token == QXmlStreamReader::Characters) {
            if (insideText || insideAnswer) {
                current_text += xml.text().toString().trimmed();
            }
        } else if (token == QXmlStreamReader::EndElement) {
            QString element_name = xml.name().toString();

            if (element_name == "text" && insideText) {
                if (current_theme >= 0 && current_theme < 5) {
                    int value_index = current_value / 100 - 1;
                    if (value_index >= 0 && value_index < 5) {
                        questions[current_theme][value_index].question = current_text;
                    }
                }
                insideText = false;
            } else if (element_name == "answer" && insideAnswer) {
                if (current_theme >= 0 && current_theme < 5) {
                    int value_index = current_value / 100 - 1;
                    if (value_index >= 0 && value_index < 5) {
                        questions[current_theme][value_index].answer = current_text;
                    }
                }
                insideAnswer = false;
            }
        }
    }

    if (xml.hasError()) {
        qDebug() << "ОШИБКА ПАРСИНГА XML:" << xml.errorString();
        return false;
    }

    return true;
}

void QuestionParser::InitializeQuestions(QVector<QVector<Question>>& questions) {
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
}

bool QuestionParser::CheckLoadedQuestions(const QVector<QVector<Question>>& questions) {
    loaded_count_ = 0;
    success_ = true;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (questions[i][j].question != "Вопрос не загружен" &&
                !questions[i][j].question.isEmpty() &&
                questions[i][j].answer != "Ответ не загружен" &&
                !questions[i][j].answer.isEmpty()) {
                loaded_count_++;
            } else {
                success_ = false;
                qDebug() << "Не загружен вопрос: тема" << i << "стоимость" << ((j + 1) * 100);
            }
        }
    }

    return success_;
}

void QuestionParser::CreateDefaultQuestions(QVector<QVector<Question>>& questions) {
    QStringList themes = {"История Древнего мира", "Средние века",
                          "Новое время", "Новейшая история", "Великие личности"};
    InitializeQuestions(questions);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            questions[i][j].question =
                QString("Вопрос по теме '%1' стоимостью %2 очков")
                    .arg(themes[i])
                    .arg((j + 1) * 100);
            questions[i][j].answer =
                QString("Правильный ответ на вопрос стоимостью %1 очков")
                    .arg((j + 1) * 100);
            questions[i][j].value = (j + 1) * 100;
            questions[i][j].answered = false;
        }
    }

    loaded_count_ = 25;
    success_ = true;
    qDebug() << "Созданы стандартные вопросы (25 шт.)";
}
