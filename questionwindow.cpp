#include "questionwindow.h"

#include <QDebug>

#include "ui_questionwindow.h"

QuestionWindow::QuestionWindow(const QString& question, const QString& answer,
                               int value, QWidget* parent)
    : QDialog(parent),
    ui_(new Ui::QuestionWindow) {
    ui_->setupUi(this);
    setWindowTitle("Вопрос за " + QString::number(value) + " очков");

    qDebug() << "QuestionWindow: Устанавливаем вопрос -" << question;
    qDebug() << "QuestionWindow: Устанавливаем ответ -" << answer;

    // Устанавливаем текст
    ui_->questionLabel->setText(question);
    ui_->answerLabel->setText(answer);

    // Настраиваем отображение
    ui_->questionLabel->setWordWrap(true);
    ui_->answerLabel->setWordWrap(true);

    // Прячем ответ и кнопки оценки
    ui_->answerLabel->setVisible(false);
    ui_->correctButton->setVisible(false);
    ui_->incorrectButton->setVisible(false);

    setMinimumSize(600, 400);
}

void QuestionWindow::on_showAnswerButton_clicked() {
    ui_->showAnswerButton->setVisible(false);
    ui_->answerLabel->setVisible(true);
    ui_->correctButton->setVisible(true);
    ui_->incorrectButton->setVisible(true);
}

void QuestionWindow::on_correctButton_clicked() {
    qDebug() << "QuestionWindow: Выбран правильный ответ";
    emit answerResult(true);
    accept();
}

void QuestionWindow::on_incorrectButton_clicked() {
    qDebug() << "QuestionWindow: Выбран неправильный ответ";
    emit answerResult(false);
    accept();
}

QuestionWindow::~QuestionWindow() {
    delete ui_;
}
