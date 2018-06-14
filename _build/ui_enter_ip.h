/********************************************************************************
** Form generated from reading UI file 'enter_ip.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTER_IP_H
#define UI_ENTER_IP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_enter_ip
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_IP;
    QLineEdit *line_IP;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *enter_ip)
    {
        if (enter_ip->objectName().isEmpty())
            enter_ip->setObjectName(QStringLiteral("enter_ip"));
        enter_ip->resize(177, 96);
        enter_ip->setMinimumSize(QSize(177, 96));
        enter_ip->setMaximumSize(QSize(177, 96));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/Mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        enter_ip->setWindowIcon(icon);
        gridLayout = new QGridLayout(enter_ip);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_IP = new QLabel(enter_ip);
        label_IP->setObjectName(QStringLiteral("label_IP"));

        verticalLayout->addWidget(label_IP);

        line_IP = new QLineEdit(enter_ip);
        line_IP->setObjectName(QStringLiteral("line_IP"));

        verticalLayout->addWidget(line_IP);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_ok = new QPushButton(enter_ip);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setEnabled(false);

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(enter_ip);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(enter_ip);
        QObject::connect(pushButton_ok, SIGNAL(clicked()), enter_ip, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), enter_ip, SLOT(reject()));

        QMetaObject::connectSlotsByName(enter_ip);
    } // setupUi

    void retranslateUi(QDialog *enter_ip)
    {
        enter_ip->setWindowTitle(QApplication::translate("enter_ip", "Dialog", nullptr));
        label_IP->setText(QApplication::translate("enter_ip", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 IP \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        pushButton_ok->setText(QApplication::translate("enter_ip", "OK", nullptr));
        pushButton_cancel->setText(QApplication::translate("enter_ip", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enter_ip: public Ui_enter_ip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTER_IP_H
