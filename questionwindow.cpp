#include "questionwindow.h"
#include "ui_questionwindow.h"
#include <QDebug>

QuestionWindow::QuestionWindow(const QString &question, const QString &answer, int value, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuestionWindow)
{
    ui->setupUi(this);
    setWindowTitle("Вопрос за " + QString::number(value) + " очков");

    qDebug() << "QuestionWindow: Устанавливаем вопрос -" << question;
    qDebug() << "QuestionWindow: Устанавливаем ответ -" << answer;

    // Устанавливаем текст
    ui->questionLabel->setText(question);
    ui->answerLabel->setText(answer);

    // Настраиваем отображение
    ui->questionLabel->setWordWrap(true);
    ui->answerLabel->setWordWrap(true);

    // Прячем ответ и кнопки оценки
    ui->answerLabel->setVisible(false);
    ui->correctButton->setVisible(false);
    ui->incorrectButton->setVisible(false);

    setMinimumSize(600, 400);
}

void QuestionWindow::on_showAnswerButton_clicked()
{
    ui->showAnswerButton->setVisible(false);
    ui->answerLabel->setVisible(true);
    ui->correctButton->setVisible(true);
    ui->incorrectButton->setVisible(true);
}

void QuestionWindow::on_correctButton_clicked()
{
    qDebug() << "QuestionWindow: Выбран правильный ответ";
    emit answerResult(true);
    accept();
}

void QuestionWindow::on_incorrectButton_clicked()
{
    qDebug() << "QuestionWindow: Выбран неправильный ответ";
    emit answerResult(false);
    accept();
}

QuestionWindow::~QuestionWindow()
{
    delete ui;
}
