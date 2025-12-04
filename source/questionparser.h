#ifndef QUESTIONPARSER_H
#define QUESTIONPARSER_H

#include <QString>
#include <QVector>
#include <QStringList>

struct Question {
    QString question;
    QString answer;
    int value;
    bool answered;
};

class QuestionParser {
public:
    QuestionParser();

    // Основной метод загрузки ТОЛЬКО из ресурсов
    bool LoadFromResource(QVector<QVector<Question>>& questions);

    // Резервный метод: создание вопросов по умолчанию
    void CreateDefaultQuestions(QVector<QVector<Question>>& questions);

    int GetLoadedCount() const { return loaded_count_; }
    bool IsSuccess() const { return success_; }

private:
    // Парсинг XML из байтового массива
    bool ParseXmlFromByteArray(const QByteArray& xmlData,
                               QVector<QVector<Question>>& questions);

    void InitializeQuestions(QVector<QVector<Question>>& questions);
    bool CheckLoadedQuestions(const QVector<QVector<Question>>& questions);

    int loaded_count_;
    bool success_;
};

#endif  // QUESTIONPARSER_H
