#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVector>
#include <QPushButton>

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

private:
    Ui::GameWindow *ui;
    void setupGame();
    void nextTurn();
    void updateScore();
    void createQuestions();
    bool loadQuestionsFromXML();

    QStringList players;
    QVector<int> scores;
    int currentPlayer;
    QVector<QVector<Question>> questions;
    QPushButton *currentQuestionButton;
};

#endif // GAMEWINDOW_H
