/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_journal;
    QAction *actionRestart;
    QAction *action_IP;
    QWidget *centralWidget;
    QPushButton *butt_connect;
    QLabel *info_ship1_my;
    QLabel *info_ship2_my;
    QLabel *num_ship1_my;
    QLabel *num_ship2_my;
    QLabel *info_ship2_my_2;
    QLabel *num_ship4_my;
    QLabel *num_ship3_my;
    QLabel *info_ship1_my_2;
    QLabel *label;
    QLineEdit *line_name;
    QLineEdit *line_password;
    QLabel *lable_Add_ships;
    QLabel *lable_Add_name;
    QLabel *lable_connect;
    QMenuBar *menuBar;
    QMenu *menuMENU;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1038, 704);
        MainWindow->setMinimumSize(QSize(1038, 704));
        MainWindow->setMaximumSize(QSize(1038, 704));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        action_journal = new QAction(MainWindow);
        action_journal->setObjectName(QStringLiteral("action_journal"));
        action_journal->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/img/journal_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_journal->setIcon(icon1);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        action_IP = new QAction(MainWindow);
        action_IP->setObjectName(QStringLiteral("action_IP"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        butt_connect = new QPushButton(centralWidget);
        butt_connect->setObjectName(QStringLiteral("butt_connect"));
        butt_connect->setEnabled(false);
        butt_connect->setGeometry(QRect(873, 25, 127, 45));
        butt_connect->setMinimumSize(QSize(127, 45));
        butt_connect->setMaximumSize(QSize(255, 90));
        butt_connect->setSizeIncrement(QSize(0, 0));
        info_ship1_my = new QLabel(centralWidget);
        info_ship1_my->setObjectName(QStringLiteral("info_ship1_my"));
        info_ship1_my->setGeometry(QRect(70, 550, 35, 35));
        info_ship1_my->setMaximumSize(QSize(35, 35));
        info_ship1_my->setStyleSheet(QStringLiteral("background-image: url(:/images/ships/img/ship1.png);"));
        info_ship2_my = new QLabel(centralWidget);
        info_ship2_my->setObjectName(QStringLiteral("info_ship2_my"));
        info_ship2_my->setGeometry(QRect(73, 585, 70, 35));
        info_ship2_my->setMaximumSize(QSize(70, 35));
        info_ship2_my->setStyleSheet(QStringLiteral("background-image: url(:/images/ships/img/ship2_h.png);"));
        num_ship1_my = new QLabel(centralWidget);
        num_ship1_my->setObjectName(QStringLiteral("num_ship1_my"));
        num_ship1_my->setGeometry(QRect(52, 555, 20, 35));
        QFont font;
        font.setFamily(QStringLiteral("Daneehand Regular"));
        font.setPointSize(14);
        num_ship1_my->setFont(font);
        num_ship2_my = new QLabel(centralWidget);
        num_ship2_my->setObjectName(QStringLiteral("num_ship2_my"));
        num_ship2_my->setGeometry(QRect(52, 590, 20, 35));
        num_ship2_my->setFont(font);
        info_ship2_my_2 = new QLabel(centralWidget);
        info_ship2_my_2->setObjectName(QStringLiteral("info_ship2_my_2"));
        info_ship2_my_2->setGeometry(QRect(196, 580, 140, 35));
        info_ship2_my_2->setMaximumSize(QSize(140, 35));
        info_ship2_my_2->setStyleSheet(QStringLiteral("background-image: url(:/images/ships/img/ship4_h.png);"));
        num_ship4_my = new QLabel(centralWidget);
        num_ship4_my->setObjectName(QStringLiteral("num_ship4_my"));
        num_ship4_my->setGeometry(QRect(175, 588, 20, 35));
        num_ship4_my->setFont(font);
        num_ship3_my = new QLabel(centralWidget);
        num_ship3_my->setObjectName(QStringLiteral("num_ship3_my"));
        num_ship3_my->setGeometry(QRect(175, 553, 20, 35));
        num_ship3_my->setFont(font);
        info_ship1_my_2 = new QLabel(centralWidget);
        info_ship1_my_2->setObjectName(QStringLiteral("info_ship1_my_2"));
        info_ship1_my_2->setGeometry(QRect(193, 545, 105, 35));
        info_ship1_my_2->setMaximumSize(QSize(105, 35));
        info_ship1_my_2->setStyleSheet(QStringLiteral("background-image: url(:/images/ships/img/ship3_h.png);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 620, 161, 10));
        QFont font1;
        font1.setFamily(QStringLiteral("Safron Modern"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label->setFont(font1);
        line_name = new QLineEdit(centralWidget);
        line_name->setObjectName(QStringLiteral("line_name"));
        line_name->setGeometry(QRect(628, 34, 119, 31));
        line_name->setMinimumSize(QSize(101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(11);
        line_name->setFont(font2);
        line_name->setStyleSheet(QStringLiteral(""));
        line_password = new QLineEdit(centralWidget);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setGeometry(QRect(750, 34, 120, 31));
        line_password->setMinimumSize(QSize(101, 31));
        line_password->setFont(font2);
        line_password->setStyleSheet(QStringLiteral(""));
        lable_Add_ships = new QLabel(centralWidget);
        lable_Add_ships->setObjectName(QStringLiteral("lable_Add_ships"));
        lable_Add_ships->setGeometry(QRect(155, 26, 311, 22));
        QFont font3;
        font3.setFamily(QStringLiteral("Astakhov Dished DL"));
        font3.setPointSize(13);
        lable_Add_ships->setFont(font3);
        lable_Add_ships->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        lable_Add_name = new QLabel(centralWidget);
        lable_Add_name->setObjectName(QStringLiteral("lable_Add_name"));
        lable_Add_name->setGeometry(QRect(155, 62, 301, 22));
        lable_Add_name->setFont(font3);
        lable_Add_name->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        lable_connect = new QLabel(centralWidget);
        lable_connect->setObjectName(QStringLiteral("lable_connect"));
        lable_connect->setGeometry(QRect(155, 99, 661, 22));
        lable_connect->setFont(font3);
        lable_connect->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1038, 20));
        menuMENU = new QMenu(menuBar);
        menuMENU->setObjectName(QStringLiteral("menuMENU"));
        QFont font4;
        font4.setPointSize(9);
        menuMENU->setFont(font4);
        menuMENU->setTearOffEnabled(false);
        menuMENU->setSeparatorsCollapsible(false);
        menuMENU->setToolTipsVisible(false);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font5;
        font5.setFamily(QStringLiteral("Astakhov Dished DL"));
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        statusBar->setFont(font5);
        statusBar->setStyleSheet(QLatin1String("color: rgb(185, 31, 25);\n"
"background-color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMENU->menuAction());
        menuMENU->addAction(action_journal);
        menuMENU->addAction(actionRestart);
        menuMENU->addAction(action_IP);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sia BATTLE", nullptr));
        action_journal->setText(QApplication::translate("MainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
#ifndef QT_NO_SHORTCUT
        action_journal->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_NO_SHORTCUT
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", nullptr));
        action_IP->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 IP \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        butt_connect->setText(QString());
        info_ship1_my->setText(QString());
        info_ship2_my->setText(QString());
        num_ship1_my->setText(QApplication::translate("MainWindow", "x4", nullptr));
        num_ship2_my->setText(QApplication::translate("MainWindow", "x3", nullptr));
        info_ship2_my_2->setText(QString());
        num_ship4_my->setText(QApplication::translate("MainWindow", "x1", nullptr));
        num_ship3_my->setText(QApplication::translate("MainWindow", "x2", nullptr));
        info_ship1_my_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \320\272\320\276\321\200\320\260\320\261\320\273\320\270", nullptr));
        line_name->setText(QApplication::translate("MainWindow", "name", nullptr));
        line_password->setText(QApplication::translate("MainWindow", "pass", nullptr));
        lable_Add_ships->setText(QApplication::translate("MainWindow", "1. \320\240\320\260\321\201\321\201\321\202\320\260\320\262\321\214\321\202\320\265 \320\272\320\276\321\200\320\260\320\261\320\273\320\270", nullptr));
        lable_Add_name->setText(QApplication::translate("MainWindow", "2. \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\221 \320\270\320\274\321\217 \320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        lable_connect->setText(QApplication::translate("MainWindow", "3. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 Connect (*\320\270\320\274\321\217 \320\270 \320\277\320\260\321\200\320\276\320\273\321\214 \320\264\320\276\320\273\320\266\320\275\321\213 \321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\202\321\214 \320\274\320\270\320\275\320\270\320\274\321\203\320\274 4 \321\201\320\270\320\274\320\262\320\276\320\273\320\260)", nullptr));
        menuMENU->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
