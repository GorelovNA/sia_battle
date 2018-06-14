#ifndef ENTER_IP_H
#define ENTER_IP_H

#include <QDialog>

namespace Ui {
class enter_ip;
}

class enter_ip : public QDialog
{
    Q_OBJECT

public:
    explicit enter_ip(QWidget *parent = 0);
    ~enter_ip();

private slots:
    void but_connect_enbl();

    void on_pushButton_ok_clicked();

private:
    Ui::enter_ip *ui;

signals:
    void IP_changed_signal(QString str);
};

#endif // ENTER_IP_H
