#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>

namespace Ui {
class GameWindow;
}

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
    explicit GameWindow(const QStringList& players, QWidget* parent = nullptr);
    ~GameWindow();

private slots:
    void handleQuestionClick();
    void handleAnswerResult(bool correct);
    void on_endGameButton_clicked();
    void onReturnToMainMenu();

private:
    bool LoadQuestionsFromXml();
    void CreateQuestions();
    void SetupGame();
    void UpdateScore();
    void NextTurn();
    void DisableAllQuestionButtons();
    void UpdatePlayersPanel();
    void CheckIfAllQuestionsAnswered();
    void AutoFinishGame();
    void ScrollToCurrentPlayer();

    Ui::GameWindow* ui_;
    QStringList players_;
    QVector<int> scores_;
    int current_player_;
    QPushButton* current_question_button_;
    QVector<QVector<Question>> questions_;
    QMainWindow* main_window_ = nullptr;
    QVector<QFrame*> player_frames_;
    int total_questions_ = 25;
    int answered_questions_ = 0;
    QVBoxLayout* players_container_layout_ = nullptr;
};

#endif // GAMEWINDOW_H
