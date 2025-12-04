#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QPushButton>
#include <QStringList>
#include <QVector>

#include "mainwindow.h"
#include "resultswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GameWindow;
}
QT_END_NAMESPACE

struct Question {
    QString question;
    QString answer;
    int value;
    bool answered;
};

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GameWindow(const QStringList& players, QWidget* parent = nullptr);
    ~GameWindow();

private slots:
    void handleQuestionClick();
    void handleAnswerResult(bool correct);
    void on_endGameButton_clicked();
    void onReturnToMainMenu();

private:
    void SetupGame();
    void NextTurn();
    void UpdateScore();
    void CreateQuestions();
    bool LoadQuestionsFromXml();
    void DisableAllQuestionButtons();
    void CheckIfAllQuestionsAnswered();

    Ui::GameWindow* ui_;
    QPointer<MainWindow> main_window_;

    QStringList players_;
    QVector<int> scores_;
    int current_player_;
    QVector<QVector<Question>> questions_;
    QPushButton* current_question_button_;
};

#endif  // GAMEWINDOW_H
