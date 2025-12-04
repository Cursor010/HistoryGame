/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *playerCountLabel;
    QSpinBox *playerCountSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *playersListLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *playersLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *startGameButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(850, 700);
        MainWindow->setMinimumSize(QSize(700, 550));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #1a1a2e;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #3498db, stop:1 #2ecc71);\n"
"    border-radius: 10px;\n"
"}"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        playerCountLabel = new QLabel(centralwidget);
        playerCountLabel->setObjectName("playerCountLabel");
        playerCountLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #e6e6e6;\n"
"    padding: 8px;\n"
"}"));

        horizontalLayout->addWidget(playerCountLabel);

        playerCountSpinBox = new QSpinBox(centralwidget);
        playerCountSpinBox->setObjectName("playerCountSpinBox");
        playerCountSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    border: 2px solid #2d4059;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 16px;\n"
"    background-color: #16213e;\n"
"    min-width: 120px;\n"
"    color: #e6e6e6;\n"
"    selection-background-color: #3498db;\n"
"    selection-color: white;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    width: 25px;\n"
"    border-radius: 4px;\n"
"    border: 1px solid #2d4059;\n"
"    background-color: #0f3460;\n"
"}\n"
"QSpinBox::up-button {\n"
"    subcontrol-position: top right;\n"
"    subcontrol-origin: border;\n"
"}\n"
"QSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"    subcontrol-origin: border;\n"
"}\n"
"QSpinBox::up-button:hover, QSpinBox::down-button:hover {\n"
"    background-color: #2d4059;\n"
"}\n"
"QSpinBox::up-button:pressed, QSpinBox::down-button:pressed {\n"
"    background-color: #1a1a2e;\n"
"}\n"
"QSpinBox::up-arrow {\n"
"    image: url(:/assets/img/up.png);\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"QSpinBox::d"
                        "own-arrow {\n"
"    image: url(:/assets/img/down.png);\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}"));
        playerCountSpinBox->setMinimum(1);
        playerCountSpinBox->setMaximum(20);
        playerCountSpinBox->setValue(2);

        horizontalLayout->addWidget(playerCountSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        playersListLabel = new QLabel(centralwidget);
        playersListLabel->setObjectName("playersListLabel");
        playersListLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #e6e6e6;\n"
"    padding: 8px;\n"
"}"));

        verticalLayout->addWidget(playersListLabel);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #16213e;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2d4059;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QScrollArea > QWidget > QWidget {\n"
"    background: transparent;\n"
"}\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #1a1a2e;\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"    margin: 2px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #2d4059;\n"
"    border-radius: 6px;\n"
"    min-height: 30px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #0f3460;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"    height: 0px;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 796, 367));
        playersLayout = new QVBoxLayout(scrollAreaWidgetContents);
        playersLayout->setSpacing(10);
        playersLayout->setObjectName("playersLayout");
        playersLayout->setContentsMargins(15, 15, 15, 15);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        playersLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(frame);

        startGameButton = new QPushButton(centralwidget);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setMinimumSize(QSize(0, 55));
        startGameButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"    margin: 10px 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #2d4059;\n"
"    color: #7f8c8d;\n"
"}"));

        verticalLayout->addWidget(startGameButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\270\320\263\321\200\321\213", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\270\320\263\321\200\321\213", nullptr));
        playerCountLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 \320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\320\263\321\200\320\276\320\272\320\276\320\262:", nullptr));
        playersListLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\235 \320\241\320\277\320\270\321\201\320\276\320\272 \320\270\320\263\321\200\320\276\320\272\320\276\320\262:", nullptr));
        startGameButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
