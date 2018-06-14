/********************************************************************************
** Form generated from reading UI file 'journal.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNAL_H
#define UI_JOURNAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Journal
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *but_clear_journal;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Journal)
    {
        if (Journal->objectName().isEmpty())
            Journal->setObjectName(QStringLiteral("Journal"));
        Journal->resize(348, 550);
        Journal->setMinimumSize(QSize(250, 300));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/journal_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        Journal->setWindowIcon(icon);
        gridLayout = new QGridLayout(Journal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(Journal);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        but_clear_journal = new QPushButton(Journal);
        but_clear_journal->setObjectName(QStringLiteral("but_clear_journal"));
        but_clear_journal->setMinimumSize(QSize(61, 21));
        but_clear_journal->setMaximumSize(QSize(61, 21));

        horizontalLayout->addWidget(but_clear_journal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Journal);

        QMetaObject::connectSlotsByName(Journal);
    } // setupUi

    void retranslateUi(QDialog *Journal)
    {
        Journal->setWindowTitle(QApplication::translate("Journal", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
        but_clear_journal->setText(QApplication::translate("Journal", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Journal: public Ui_Journal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_H
