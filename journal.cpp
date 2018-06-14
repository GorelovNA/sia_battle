#include "journal.h"
#include "ui_journal.h"
#include <QTime>

Journal::Journal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Journal)
{
    ui->setupUi(this);
}

void Journal::print_to_journal(const QString &str){
    ui->listWidget->addItem(QTime::currentTime().toString()+"  " + str);

}



Journal::~Journal()
{
    delete ui;
}

void Journal::on_but_clear_journal_clicked()
{
    ui->listWidget->clear();
}
