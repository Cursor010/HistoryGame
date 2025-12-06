/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainHorizontalLayout;
    QVBoxLayout *gameBoardLayout;
    QFrame *infoFrame;
    QHBoxLayout *infoLayout;
    QLabel *currentPlayerLabel;
    QLabel *scoreLabel;
    QLabel *backgroundImageLabel;
    QFrame *gameBoardFrame;
    QGridLayout *gameGridLayout;
    QLabel *theme1Label;
    QPushButton *theme1_100;
    QPushButton *theme1_200;
    QPushButton *theme1_300;
    QPushButton *theme1_400;
    QPushButton *theme1_500;
    QLabel *theme2Label;
    QPushButton *theme2_100;
    QPushButton *theme2_200;
    QPushButton *theme2_300;
    QPushButton *theme2_400;
    QPushButton *theme2_500;
    QLabel *theme3Label;
    QPushButton *theme3_100;
    QPushButton *theme3_200;
    QPushButton *theme3_300;
    QPushButton *theme3_400;
    QPushButton *theme3_500;
    QLabel *theme4Label;
    QPushButton *theme4_100;
    QPushButton *theme4_200;
    QPushButton *theme4_300;
    QPushButton *theme4_400;
    QPushButton *theme4_500;
    QLabel *theme5Label;
    QPushButton *theme5_100;
    QPushButton *theme5_200;
    QPushButton *theme5_300;
    QPushButton *theme5_400;
    QPushButton *theme5_500;
    QHBoxLayout *bottomLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *endGameButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *playersPanel;
    QVBoxLayout *playersPanelLayout;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(1500, 950);
        GameWindow->setMinimumSize(QSize(1400, 850));
        GameWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #1a1a2e;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName("centralwidget");
        mainHorizontalLayout = new QHBoxLayout(centralwidget);
        mainHorizontalLayout->setSpacing(20);
        mainHorizontalLayout->setObjectName("mainHorizontalLayout");
        mainHorizontalLayout->setContentsMargins(15, 15, 15, 15);
        gameBoardLayout = new QVBoxLayout();
        gameBoardLayout->setSpacing(15);
        gameBoardLayout->setObjectName("gameBoardLayout");
        infoFrame = new QFrame(centralwidget);
        infoFrame->setObjectName("infoFrame");
        infoFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #0f3460, stop:1 #16213e);\n"
"    border-radius: 12px;\n"
"    border: 3px solid #2d4059;\n"
"    padding: 10px;\n"
"}"));
        infoFrame->setFrameShape(QFrame::StyledPanel);
        infoFrame->setFrameShadow(QFrame::Raised);
        infoLayout = new QHBoxLayout(infoFrame);
        infoLayout->setSpacing(40);
        infoLayout->setObjectName("infoLayout");
        infoLayout->setContentsMargins(20, 8, 20, 8);
        currentPlayerLabel = new QLabel(infoFrame);
        currentPlayerLabel->setObjectName("currentPlayerLabel");
        currentPlayerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: #e6e6e6;\n"
"    background: transparent;\n"
"    padding: 8px 15px;\n"
"}"));
        currentPlayerLabel->setAlignment(Qt::AlignCenter);

        infoLayout->addWidget(currentPlayerLabel);

        scoreLabel = new QLabel(infoFrame);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: #ffd700;\n"
"    background: transparent;\n"
"    padding: 8px 15px;\n"
"}"));
        scoreLabel->setAlignment(Qt::AlignCenter);

        infoLayout->addWidget(scoreLabel);


        gameBoardLayout->addWidget(infoFrame);

        backgroundImageLabel = new QLabel(centralwidget);
        backgroundImageLabel->setObjectName("backgroundImageLabel");
        backgroundImageLabel->setMinimumSize(QSize(0, 100));
        backgroundImageLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px;\n"
"    border: 2px solid #2d4059;\n"
"    background-color: #16213e;\n"
"    background-image: url(:/assets/img/bg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: contain;\n"
"}"));
        backgroundImageLabel->setAlignment(Qt::AlignCenter);

        gameBoardLayout->addWidget(backgroundImageLabel);

        gameBoardFrame = new QFrame(centralwidget);
        gameBoardFrame->setObjectName("gameBoardFrame");
        gameBoardFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #16213e;\n"
"    border-radius: 15px;\n"
"    border: 3px solid #2d4059;\n"
"}"));
        gameBoardFrame->setFrameShape(QFrame::StyledPanel);
        gameBoardFrame->setFrameShadow(QFrame::Raised);
        gameGridLayout = new QGridLayout(gameBoardFrame);
        gameGridLayout->setSpacing(12);
        gameGridLayout->setObjectName("gameGridLayout");
        gameGridLayout->setContentsMargins(20, 20, 20, 20);
        theme1Label = new QLabel(gameBoardFrame);
        theme1Label->setObjectName("theme1Label");
        theme1Label->setMinimumSize(QSize(160, 70));
        theme1Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"    font-size: 16pt;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1c5a7d;\n"
"}"));
        theme1Label->setAlignment(Qt::AlignCenter);

        gameGridLayout->addWidget(theme1Label, 0, 0, 1, 1);

        theme1_100 = new QPushButton(gameBoardFrame);
        theme1_100->setObjectName("theme1_100");
        theme1_100->setMinimumSize(QSize(130, 85));
        theme1_100->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border: 2px solid #1c5a7d;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"    border: 2px solid #144a69;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme1_100, 0, 1, 1, 1);

        theme1_200 = new QPushButton(gameBoardFrame);
        theme1_200->setObjectName("theme1_200");
        theme1_200->setMinimumSize(QSize(130, 85));
        theme1_200->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border: 2px solid #1c5a7d;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"    border: 2px solid #144a69;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme1_200, 0, 2, 1, 1);

        theme1_300 = new QPushButton(gameBoardFrame);
        theme1_300->setObjectName("theme1_300");
        theme1_300->setMinimumSize(QSize(130, 85));
        theme1_300->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border: 2px solid #1c5a7d;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"    border: 2px solid #144a69;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme1_300, 0, 3, 1, 1);

        theme1_400 = new QPushButton(gameBoardFrame);
        theme1_400->setObjectName("theme1_400");
        theme1_400->setMinimumSize(QSize(130, 85));
        theme1_400->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border: 2px solid #1c5a7d;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"    border: 2px solid #144a69;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme1_400, 0, 4, 1, 1);

        theme1_500 = new QPushButton(gameBoardFrame);
        theme1_500->setObjectName("theme1_500");
        theme1_500->setMinimumSize(QSize(130, 85));
        theme1_500->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    color: white;\n"
"    border: 2px solid #1c5a7d;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2980b9, stop:1 #1c5a7d);\n"
"    border: 2px solid #144a69;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1c5a7d, stop:1 #144a69);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme1_500, 0, 5, 1, 1);

        theme2Label = new QLabel(gameBoardFrame);
        theme2Label->setObjectName("theme2Label");
        theme2Label->setMinimumSize(QSize(160, 70));
        theme2Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"    font-size: 16pt;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1e8449;\n"
"}"));
        theme2Label->setAlignment(Qt::AlignCenter);

        gameGridLayout->addWidget(theme2Label, 1, 0, 1, 1);

        theme2_100 = new QPushButton(gameBoardFrame);
        theme2_100->setObjectName("theme2_100");
        theme2_100->setMinimumSize(QSize(130, 85));
        theme2_100->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border: 2px solid #1e8449;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"    border: 2px solid #196f3d;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme2_100, 1, 1, 1, 1);

        theme2_200 = new QPushButton(gameBoardFrame);
        theme2_200->setObjectName("theme2_200");
        theme2_200->setMinimumSize(QSize(130, 85));
        theme2_200->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border: 2px solid #1e8449;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"    border: 2px solid #196f3d;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme2_200, 1, 2, 1, 1);

        theme2_300 = new QPushButton(gameBoardFrame);
        theme2_300->setObjectName("theme2_300");
        theme2_300->setMinimumSize(QSize(130, 85));
        theme2_300->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border: 2px solid #1e8449;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"    border: 2px solid #196f3d;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme2_300, 1, 3, 1, 1);

        theme2_400 = new QPushButton(gameBoardFrame);
        theme2_400->setObjectName("theme2_400");
        theme2_400->setMinimumSize(QSize(130, 85));
        theme2_400->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border: 2px solid #1e8449;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"    border: 2px solid #196f3d;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme2_400, 1, 4, 1, 1);

        theme2_500 = new QPushButton(gameBoardFrame);
        theme2_500->setObjectName("theme2_500");
        theme2_500->setMinimumSize(QSize(130, 85));
        theme2_500->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #2ecc71, stop:1 #27ae60);\n"
"    color: white;\n"
"    border: 2px solid #1e8449;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #27ae60, stop:1 #219653);\n"
"    border: 2px solid #196f3d;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #219653, stop:1 #1e8449);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme2_500, 1, 5, 1, 1);

        theme3Label = new QLabel(gameBoardFrame);
        theme3Label->setObjectName("theme3Label");
        theme3Label->setMinimumSize(QSize(160, 70));
        theme3Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"    font-size: 16pt;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #922b21;\n"
"}"));
        theme3Label->setAlignment(Qt::AlignCenter);

        gameGridLayout->addWidget(theme3Label, 2, 0, 1, 1);

        theme3_100 = new QPushButton(gameBoardFrame);
        theme3_100->setObjectName("theme3_100");
        theme3_100->setMinimumSize(QSize(130, 85));
        theme3_100->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border: 2px solid #922b21;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"    border: 2px solid #78281f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme3_100, 2, 1, 1, 1);

        theme3_200 = new QPushButton(gameBoardFrame);
        theme3_200->setObjectName("theme3_200");
        theme3_200->setMinimumSize(QSize(130, 85));
        theme3_200->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border: 2px solid #922b21;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"    border: 2px solid #78281f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme3_200, 2, 2, 1, 1);

        theme3_300 = new QPushButton(gameBoardFrame);
        theme3_300->setObjectName("theme3_300");
        theme3_300->setMinimumSize(QSize(130, 85));
        theme3_300->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border: 2px solid #922b21;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"    border: 2px solid #78281f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme3_300, 2, 3, 1, 1);

        theme3_400 = new QPushButton(gameBoardFrame);
        theme3_400->setObjectName("theme3_400");
        theme3_400->setMinimumSize(QSize(130, 85));
        theme3_400->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border: 2px solid #922b21;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"    border: 2px solid #78281f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme3_400, 2, 4, 1, 1);

        theme3_500 = new QPushButton(gameBoardFrame);
        theme3_500->setObjectName("theme3_500");
        theme3_500->setMinimumSize(QSize(130, 85));
        theme3_500->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    border: 2px solid #922b21;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"    border: 2px solid #78281f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme3_500, 2, 5, 1, 1);

        theme4Label = new QLabel(gameBoardFrame);
        theme4Label->setObjectName("theme4Label");
        theme4Label->setMinimumSize(QSize(160, 70));
        theme4Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"    font-size: 15pt;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #9c640c;\n"
"}"));
        theme4Label->setAlignment(Qt::AlignCenter);

        gameGridLayout->addWidget(theme4Label, 3, 0, 1, 1);

        theme4_100 = new QPushButton(gameBoardFrame);
        theme4_100->setObjectName("theme4_100");
        theme4_100->setMinimumSize(QSize(130, 85));
        theme4_100->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border: 2px solid #9c640c;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d68910, stop:1 #b9770e);\n"
"    border: 2px solid #7e5109;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #b9770e, stop:1 #9c640c);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme4_100, 3, 1, 1, 1);

        theme4_200 = new QPushButton(gameBoardFrame);
        theme4_200->setObjectName("theme4_200");
        theme4_200->setMinimumSize(QSize(130, 85));
        theme4_200->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border: 2px solid #9c640c;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d68910, stop:1 #b9770e);\n"
"    border: 2px solid #7e5109;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #b9770e, stop:1 #9c640c);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme4_200, 3, 2, 1, 1);

        theme4_300 = new QPushButton(gameBoardFrame);
        theme4_300->setObjectName("theme4_300");
        theme4_300->setMinimumSize(QSize(130, 85));
        theme4_300->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border: 2px solid #9c640c;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d68910, stop:1 #b9770e);\n"
"    border: 2px solid #7e5109;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #b9770e, stop:1 #9c640c);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme4_300, 3, 3, 1, 1);

        theme4_400 = new QPushButton(gameBoardFrame);
        theme4_400->setObjectName("theme4_400");
        theme4_400->setMinimumSize(QSize(130, 85));
        theme4_400->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border: 2px solid #9c640c;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d68910, stop:1 #b9770e);\n"
"    border: 2px solid #7e5109;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #b9770e, stop:1 #9c640c);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme4_400, 3, 4, 1, 1);

        theme4_500 = new QPushButton(gameBoardFrame);
        theme4_500->setObjectName("theme4_500");
        theme4_500->setMinimumSize(QSize(130, 85));
        theme4_500->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f39c12, stop:1 #d68910);\n"
"    color: white;\n"
"    border: 2px solid #9c640c;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d68910, stop:1 #b9770e);\n"
"    border: 2px solid #7e5109;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #b9770e, stop:1 #9c640c);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme4_500, 3, 5, 1, 1);

        theme5Label = new QLabel(gameBoardFrame);
        theme5Label->setObjectName("theme5Label");
        theme5Label->setMinimumSize(QSize(160, 70));
        theme5Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-weight: bold;\n"
"    font-size: 16pt;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #6c3483;\n"
"}"));
        theme5Label->setAlignment(Qt::AlignCenter);

        gameGridLayout->addWidget(theme5Label, 4, 0, 1, 1);

        theme5_100 = new QPushButton(gameBoardFrame);
        theme5_100->setObjectName("theme5_100");
        theme5_100->setMinimumSize(QSize(130, 85));
        theme5_100->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border: 2px solid #6c3483;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #8e44ad, stop:1 #7d3c98);\n"
"    border: 2px solid #5b2c6f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7d3c98, stop:1 #6c3483);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme5_100, 4, 1, 1, 1);

        theme5_200 = new QPushButton(gameBoardFrame);
        theme5_200->setObjectName("theme5_200");
        theme5_200->setMinimumSize(QSize(130, 85));
        theme5_200->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border: 2px solid #6c3483;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #8e44ad, stop:1 #7d3c98);\n"
"    border: 2px solid #5b2c6f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7d3c98, stop:1 #6c3483);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme5_200, 4, 2, 1, 1);

        theme5_300 = new QPushButton(gameBoardFrame);
        theme5_300->setObjectName("theme5_300");
        theme5_300->setMinimumSize(QSize(130, 85));
        theme5_300->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border: 2px solid #6c3483;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #8e44ad, stop:1 #7d3c98);\n"
"    border: 2px solid #5b2c6f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7d3c98, stop:1 #6c3483);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme5_300, 4, 3, 1, 1);

        theme5_400 = new QPushButton(gameBoardFrame);
        theme5_400->setObjectName("theme5_400");
        theme5_400->setMinimumSize(QSize(130, 85));
        theme5_400->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border: 2px solid #6c3483;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #8e44ad, stop:1 #7d3c98);\n"
"    border: 2px solid #5b2c6f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7d3c98, stop:1 #6c3483);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme5_400, 4, 4, 1, 1);

        theme5_500 = new QPushButton(gameBoardFrame);
        theme5_500->setObjectName("theme5_500");
        theme5_500->setMinimumSize(QSize(130, 85));
        theme5_500->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 22pt;\n"
"    font-weight: bold;\n"
"    padding: 15px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9b59b6, stop:1 #8e44ad);\n"
"    color: white;\n"
"    border: 2px solid #6c3483;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #8e44ad, stop:1 #7d3c98);\n"
"    border: 2px solid #5b2c6f;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7d3c98, stop:1 #6c3483);\n"
"}\n"
"QPushButton:disabled {\n"
"    background: #7f8c8d;\n"
"    color: #bdc3c7;\n"
"    border: 2px solid #636e72;\n"
"}"));

        gameGridLayout->addWidget(theme5_500, 4, 5, 1, 1);


        gameBoardLayout->addWidget(gameBoardFrame);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(15);
        bottomLayout->setObjectName("bottomLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        bottomLayout->addItem(horizontalSpacer);

        endGameButton = new QPushButton(centralwidget);
        endGameButton->setObjectName("endGameButton");
        endGameButton->setMinimumSize(QSize(0, 65));
        endGameButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e74c3c, stop:1 #c0392b);\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 18px 35px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c0392b, stop:1 #a93226);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #a93226, stop:1 #922b21);\n"
"}"));

        bottomLayout->addWidget(endGameButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        bottomLayout->addItem(horizontalSpacer_2);


        gameBoardLayout->addLayout(bottomLayout);


        mainHorizontalLayout->addLayout(gameBoardLayout);

        playersPanel = new QFrame(centralwidget);
        playersPanel->setObjectName("playersPanel");
        playersPanel->setMinimumSize(QSize(350, 0));
        playersPanel->setMaximumSize(QSize(400, 16777215));
        playersPanel->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #0c2461, stop:1 #1e3799);\n"
"    border-radius: 15px;\n"
"    border: 3px solid #0a3d62;\n"
"    padding: 0px;\n"
"}"));
        playersPanel->setFrameShape(QFrame::StyledPanel);
        playersPanel->setFrameShadow(QFrame::Raised);
        playersPanelLayout = new QVBoxLayout(playersPanel);
        playersPanelLayout->setSpacing(0);
        playersPanelLayout->setObjectName("playersPanelLayout");
        playersPanelLayout->setContentsMargins(0, 0, 0, 0);

        mainHorizontalLayout->addWidget(playersPanel);

        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\222\320\270\320\272\321\202\320\276\321\200\320\270\320\275\320\260", nullptr));
        currentPlayerLabel->setText(QCoreApplication::translate("GameWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\270\320\263\321\200\320\276\320\272: \320\230\320\263\321\200\320\276\320\272 1", nullptr));
        scoreLabel->setText(QCoreApplication::translate("GameWindow", "\320\241\321\207\320\265\321\202: 0", nullptr));
        backgroundImageLabel->setText(QString());
        theme1Label->setText(QCoreApplication::translate("GameWindow", "\360\237\223\232 \320\242\320\265\321\200\320\274\320\270\320\275\321\213", nullptr));
        theme1_100->setText(QCoreApplication::translate("GameWindow", "100", nullptr));
        theme1_200->setText(QCoreApplication::translate("GameWindow", "200", nullptr));
        theme1_300->setText(QCoreApplication::translate("GameWindow", "300", nullptr));
        theme1_400->setText(QCoreApplication::translate("GameWindow", "400", nullptr));
        theme1_500->setText(QCoreApplication::translate("GameWindow", "500", nullptr));
        theme2Label->setText(QCoreApplication::translate("GameWindow", "\360\237\221\244 \320\233\320\270\321\207\320\275\320\276\321\201\321\202\320\270", nullptr));
        theme2_100->setText(QCoreApplication::translate("GameWindow", "100", nullptr));
        theme2_200->setText(QCoreApplication::translate("GameWindow", "200", nullptr));
        theme2_300->setText(QCoreApplication::translate("GameWindow", "300", nullptr));
        theme2_400->setText(QCoreApplication::translate("GameWindow", "400", nullptr));
        theme2_500->setText(QCoreApplication::translate("GameWindow", "500", nullptr));
        theme3Label->setText(QCoreApplication::translate("GameWindow", "\360\237\223\205 \320\224\320\260\321\202\321\213", nullptr));
        theme3_100->setText(QCoreApplication::translate("GameWindow", "100", nullptr));
        theme3_200->setText(QCoreApplication::translate("GameWindow", "200", nullptr));
        theme3_300->setText(QCoreApplication::translate("GameWindow", "300", nullptr));
        theme3_400->setText(QCoreApplication::translate("GameWindow", "400", nullptr));
        theme3_500->setText(QCoreApplication::translate("GameWindow", "500", nullptr));
        theme4Label->setText(QCoreApplication::translate("GameWindow", "\360\237\217\233\357\270\217 \320\237\320\276\320\273\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        theme4_100->setText(QCoreApplication::translate("GameWindow", "100", nullptr));
        theme4_200->setText(QCoreApplication::translate("GameWindow", "200", nullptr));
        theme4_300->setText(QCoreApplication::translate("GameWindow", "300", nullptr));
        theme4_400->setText(QCoreApplication::translate("GameWindow", "400", nullptr));
        theme4_500->setText(QCoreApplication::translate("GameWindow", "500", nullptr));
        theme5Label->setText(QCoreApplication::translate("GameWindow", "\360\237\223\242 \320\233\320\276\320\267\321\203\320\275\320\263\320\270", nullptr));
        theme5_100->setText(QCoreApplication::translate("GameWindow", "100", nullptr));
        theme5_200->setText(QCoreApplication::translate("GameWindow", "200", nullptr));
        theme5_300->setText(QCoreApplication::translate("GameWindow", "300", nullptr));
        theme5_400->setText(QCoreApplication::translate("GameWindow", "400", nullptr));
        theme5_500->setText(QCoreApplication::translate("GameWindow", "500", nullptr));
        endGameButton->setText(QCoreApplication::translate("GameWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
