/********************************************************************************
** Form generated from reading UI file 'resultswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSWINDOW_H
#define UI_RESULTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResultsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTableWidget *tableWidget;
    QLabel *totalScoreLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *ResultsWindow)
    {
        if (ResultsWindow->objectName().isEmpty())
            ResultsWindow->setObjectName("ResultsWindow");
        ResultsWindow->resize(900, 700);
        ResultsWindow->setMinimumSize(QSize(800, 600));
        ResultsWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #1a1a2e;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        verticalLayout = new QVBoxLayout(ResultsWindow);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(ResultsWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    padding: 20px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #3498db, stop:1 #2ecc71);\n"
"    border-radius: 15px;\n"
"    border: 3px solid #2d4059;\n"
"}"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        tableWidget = new QTableWidget(ResultsWindow);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #16213e;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2d4059;\n"
"    gridline-color: #2d4059;\n"
"    color: #e6e6e6;\n"
"    font-size: 14px;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #2d4059;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #0f3460;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #0f3460;\n"
"    color: white;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    border-right: 1px solid #2d4059;\n"
"}\n"
"QHeaderView::section:last {\n"
"    border-right: none;\n"
"}"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableWidget);

        totalScoreLabel = new QLabel(ResultsWindow);
        totalScoreLabel->setObjectName("totalScoreLabel");
        totalScoreLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #e6e6e6;\n"
"    padding: 15px;\n"
"    background-color: #16213e;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2ecc71;\n"
"}"));
        totalScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(totalScoreLabel);

        closeButton = new QPushButton(ResultsWindow);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(0, 55));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 15px 30px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(ResultsWindow);

        QMetaObject::connectSlotsByName(ResultsWindow);
    } // setupUi

    void retranslateUi(QDialog *ResultsWindow)
    {
        ResultsWindow->setWindowTitle(QCoreApplication::translate("ResultsWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        titleLabel->setText(QCoreApplication::translate("ResultsWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\270\320\263\321\200\321\213", nullptr));
        totalScoreLabel->setText(QCoreApplication::translate("ResultsWindow", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\276\321\207\320\272\320\276\320\262:", nullptr));
        closeButton->setText(QCoreApplication::translate("ResultsWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultsWindow: public Ui_ResultsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSWINDOW_H
