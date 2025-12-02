#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVector>
#include <QPushButton>
#include "resultswindow.h"  // Добавьте эту строку
#include "mainwindow.h" // Добавить эту строку

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

struct Question {
    QString question;
    QString answer;
    int value;
    bool answered;
};

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(const QStringList &players, QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void handleQuestionClick();
    void handleAnswerResult(bool correct);
    void on_endGameButton_clicked();  // Добавьте эту строку

private:
    Ui::GameWindow *ui;
    void setupGame();
    void nextTurn();
    void updateScore();
    void createQuestions();
    bool loadQuestionsFromXML();
    void disableAllQuestionButtons();  // Добавьте эту строку

    QStringList players;
    QVector<int> scores;
    int currentPlayer;
    QVector<QVector<Question>> questions;
    QPushButton *currentQuestionButton;
};

#endif // GAMEWINDOW_H
