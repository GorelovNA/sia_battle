#include "enter_ip.h"
#include "ui_enter_ip.h"
#include <QRegExpValidator>

enter_ip::enter_ip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter_ip)
{
    ui->setupUi(this);

    /**/
    QRegExp exp1_IP("[0-9]{1,3}[.]{1,1}[0-9]{1,3}[.]{1,1}[0-9]{1,3}[.]{1,1}[0-9]{1,3}");
    ui->line_IP->setValidator(new QRegExpValidator(exp1_IP,this));

    /*кнопка загорается только при правильноm вводе поля ip+port*/
    connect(ui->line_IP,SIGNAL(textChanged(QString)),this, SLOT(but_connect_enbl()));


}

enter_ip::~enter_ip()
{
    delete ui;
}

void enter_ip::but_connect_enbl(){
    ui->pushButton_ok->setEnabled((ui->line_IP->hasAcceptableInput()));
}

void enter_ip::on_pushButton_ok_clicked()
{
    emit IP_changed_signal(ui->line_IP->text());
}
