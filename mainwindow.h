#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <field.h>
#include <sia_client.h>
#include <QVector>
//#include <defines.h>
#include <QLabel>
#include <journal.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    void mousePressEvent( QMouseEvent* ev );

private slots:
    void on_butt_connect_clicked();
    void name_pass_edit();
    void redrow_func(int arr[FIELD_ROWS][FIELD_COLUMNS]);
    void slot_send_name_pass();


    void on_action_journal_triggered(bool checked);
    void close_journal();

    void on_action_IP_triggered();
    void update_server_IP(const QString& str);
    void slot_send_com_to_serv(const int &i);

    void on_actionRestart_triggered();

private:
    Ui::MainWindow *ui;
    QString *HOST_IP;// = "127.0.0.1";

    field *my_field;
    field *enemy_field;
    sia_client *client;
    Journal *jrnl_list;
    state GAME_status;

    //QWidget *Journal;   //окно журнала
    //QWidgetList *Journal;   //окно журнала

    QLabel *Lab[10][10];//[10][10];
    QLabel *Ships_info_your[4][2]; //ифно сколько кораблей осталось 4 корабля, и текст
    QLabel *Ships_info_enemy[4][2]; //ифно сколько кораблей осталось


    //позже сделать класс images
    QPixmap ship1;
    QPixmap ship2_h;
    QPixmap ship2_v;
    QPixmap ship3_h;
    QPixmap ship3_v;
    QPixmap ship4_h;
    QPixmap ship4_v;

    bool but_con_state;


    void presettings();

};

#endif // MAINWINDOW_H
