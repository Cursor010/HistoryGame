/********************************************************************************
** Form generated from reading UI file 'questionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONWINDOW_H
#define UI_QUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QFrame *answerFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *answerLabel;
    QPushButton *showAnswerButton;
    QHBoxLayout *resultButtonsLayout;
    QPushButton *correctButton;
    QPushButton *incorrectButton;

    void setupUi(QDialog *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName("QuestionWindow");
        QuestionWindow->resize(800, 600);
        QuestionWindow->setMinimumSize(QSize(600, 450));
        QuestionWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #1a1a2e;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        verticalLayout = new QVBoxLayout(QuestionWindow);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        questionLabel = new QLabel(QuestionWindow);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setMinimumSize(QSize(0, 150));
        questionLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: 500;\n"
"    padding: 25px;\n"
"    background-color: #16213e;\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 15px;\n"
"    line-height: 1.4;\n"
"}"));
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setWordWrap(true);

        verticalLayout->addWidget(questionLabel);

        answerFrame = new QFrame(QuestionWindow);
        answerFrame->setObjectName("answerFrame");
        answerFrame->setMinimumSize(QSize(0, 150));
        answerFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #16213e;\n"
"    border: 2px dashed #7f8c8d;\n"
"    border-radius: 15px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(answerFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        answerLabel = new QLabel(answerFrame);
        answerLabel->setObjectName("answerLabel");
        answerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: 500;\n"
"    padding: 25px;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    line-height: 1.4;\n"
"}"));
        answerLabel->setAlignment(Qt::AlignCenter);
        answerLabel->setWordWrap(true);

        verticalLayout_2->addWidget(answerLabel);


        verticalLayout->addWidget(answerFrame);

        showAnswerButton = new QPushButton(QuestionWindow);
        showAnswerButton->setObjectName("showAnswerButton");
        showAnswerButton->setMinimumSize(QSize(0, 55));
        showAnswerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #2573a7);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2573a7, stop:1 #1f618d);\n"
"}"));

        verticalLayout->addWidget(showAnswerButton);

        resultButtonsLayout = new QHBoxLayout();
        resultButtonsLayout->setSpacing(20);
        resultButtonsLayout->setObjectName("resultButtonsLayout");
        correctButton = new QPushButton(QuestionWindow);
        correctButton->setObjectName("correctButton");
        correctButton->setMinimumSize(QSize(0, 55));
        correctButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}"));

        resultButtonsLayout->addWidget(correctButton);

        incorrectButton = new QPushButton(QuestionWindow);
        incorrectButton->setObjectName("incorrectButton");
        incorrectButton->setMinimumSize(QSize(0, 55));
        incorrectButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}"));

        resultButtonsLayout->addWidget(incorrectButton);


        verticalLayout->addLayout(resultButtonsLayout);


        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QDialog *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        questionLabel->setText(QCoreApplication::translate("QuestionWindow", "\320\242\320\265\320\272\321\201\321\202 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
        answerLabel->setText(QString());
        showAnswerButton->setText(QCoreApplication::translate("QuestionWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        correctButton->setText(QCoreApplication::translate("QuestionWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\276\321\202\320\262\320\265\321\202", nullptr));
        incorrectButton->setText(QCoreApplication::translate("QuestionWindow", "\320\235\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\276\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONWINDOW_H
