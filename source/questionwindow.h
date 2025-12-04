#ifndef QUESTIONWINDOW_H
#define QUESTIONWINDOW_H

#include <QDialog>

namespace Ui {
class QuestionWindow;
}

class QuestionWindow : public QDialog {
    Q_OBJECT

public:
    explicit QuestionWindow(const QString& question, const QString& answer,
                            int value, QWidget* parent = nullptr);
    ~QuestionWindow();

signals:
    void answerResult(bool correct);

private slots:
    void on_showAnswerButton_clicked();
    void on_correctButton_clicked();
    void on_incorrectButton_clicked();

private:
    Ui::QuestionWindow* ui_;
};

#endif  // QUESTIONWINDOW_H
