#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enter_ip.h"
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFontDatabase>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    HOST_IP(new QString("127.0.0.1")),
    my_field(new field(this)),
    enemy_field(new field(this)),    
    client(new sia_client(this)),
    jrnl_list(new Journal(this)),
    GAME_status(GAME_START),
    but_con_state(1)
{
    ui->setupUi(this);
    presettings();

//журнал
    connect(jrnl_list, &Journal::rejected, this, &MainWindow::close_journal);
//клиент
    connect(client, &sia_client::print_client_signal, jrnl_list, &Journal::print_to_journal);
    connect(client->sock, &QTcpSocket::connected,   client,&sia_client::slot_sock_connected);
    connect(client->sock, &QTcpSocket::connected,   this,&MainWindow::slot_send_name_pass);
    connect(client->sock, &QTcpSocket::disconnected,client,&sia_client::slot_sock_disconnected);
    connect(client->sock, &QTcpSocket::readyRead, client,&sia_client::slot_ready_read);
    connect(client->sock, SIGNAL(error(QAbstractSocket::SocketError)),client,SLOT(slot_sock_error(QAbstractSocket::SocketError)));
    connect(client, &sia_client::send_com_to_serv_signal, this, &MainWindow::slot_send_com_to_serv);
//поля
    connect(my_field,&field::redrow_field,this,&MainWindow::redrow_func);
    connect(my_field,&field::print_to_statusbar,ui->statusBar, &QStatusBar::showMessage);
//имя пароль
    QRegExp exp1_NAME("[a-zA-Z0-9]{4,10}");
    QRegExp exp1_PASWORD("[a-zA-Z0-9]{4,15}");
    ui->line_name->setValidator(new QRegExpValidator(exp1_NAME,this));
    ui->line_password->setValidator(new QRegExpValidator(exp1_PASWORD,this));
   /*кнопка загорается только при правильноm вводе поля имя+пароль*/
    connect(ui->line_name,&QLineEdit::textChanged,this, &MainWindow::name_pass_edit);
    connect(ui->line_password,&QLineEdit::textChanged,this, &MainWindow::name_pass_edit);


    //сделать: у климана не отрисовывается фон программы и шрифты. Кнопка отрисовывается
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::name_pass_edit(){
    if((ui->line_name->hasAcceptableInput()) && (ui->line_password->hasAcceptableInput())){
        ui->butt_connect->setEnabled(1);
        ui->lable_Add_name->setVisible(0);
    }
    else{
        ui->lable_Add_name->setVisible(1);
        ui->statusBar->showMessage("Имя и Пароль не может быть короче 4х символов",400);
        if(but_con_state) ui->butt_connect->setEnabled(0);
    }
}

void MainWindow::on_butt_connect_clicked()
{
    if(but_con_state){ //коннектимся
        if(GAME_status==SHIPS_PLACED){
            ui->butt_connect->setStyleSheet("QPushButton{border-image: url(:/images/img/discon_un.png) stretch;}"
            "QPushButton:hover{border-image: url(:/images/img/discon_act.png) stretch;}"
            "QPushButton:pressed{border-image: url(:/images/img/discon_pressed.png) stretch;}");
            but_con_state=0;

            client->sock->connectToHost(*HOST_IP,HOST_PORT);
            ui->lable_connect->setVisible(0);
        }
        else ui->statusBar->showMessage("РАССТАВЬТЕ КОРАБЛИ!",4000);

    }
    else { //дисконнектимся
        GAME_status=SHIPS_PLACED;
        ui->butt_connect->setStyleSheet("QPushButton{border-image: url(:/images/img/connect_unactive.png) stretch;}"
        "QPushButton:hover{border-image: url(:/images/img/connect_active.png) stretch;}"
        "QPushButton:pressed{border-image: url(:/images/img/connect_pressed.png) stretch;}");
        but_con_state=1;

        client->sock->abort();
    }
}
void MainWindow::slot_send_name_pass(){
    GAME_status = CONNECTED_TO_SERVER;
    ui->statusBar->showMessage("successfully connected to server",3000);
   // client->sock->write("[connect][" + ui->line_name->text()+"]["+ui->line_password->text()+"]");
    QByteArray Ba;
    Ba.append(":connect:" + ui->line_name->text() + ":" + ui->line_password->text() + ":");
    client->sock->write(Ba);

}



void MainWindow::mousePressEvent( QMouseEvent* ev )
{
    int pole;
    QPoint pos = ev->pos();
    pos.setY(pos.y() - this->centralWidget()->y());//учли main bar

    if(pos.y() < MY_FIELD_COORD_Y || pos.y() > MY_FIELD_COORD_Y+(FIELD_CELL_HIEGH*FIELD_ROWS)
            || pos.x() < MY_FIELD_COORD_X
            || pos.x() > ENEMY_FIELD_COORD_X+(FIELD_CELL_WIDTH*FIELD_COLUMNS)
            ||(pos.x()>(MY_FIELD_COORD_X+FIELD_CELL_WIDTH*FIELD_COLUMNS) && pos.x()<ENEMY_FIELD_COORD_X)
    ) {qDebug() <<"тут нет поля!"; ui->statusBar->showMessage("Тут нет поля!",3000);}

    else{


        if(pos.x()<(MY_FIELD_COORD_X+FIELD_CELL_WIDTH*FIELD_COLUMNS)) //если кликнули по моему полю
        {
            if(GAME_status<2){  //если игра еще не началась {GAME_START=0, SHIPS_PLACED=1, CONNECTED_...
                pole = SHIPS_PLACED;//my field
                //qDebug() << "my field: x= "<<pos.x()<<", y= "<< pos.y();
                my_field->set_point(pos,pole);}
            else ui->statusBar->showMessage("Игра началась! Вы не можете изменять своё поле",2000);
        }
        else{
            if(GAME_status==YOU_TURN){
                pole = YOU_TURN;//enemy field     //если кликнули по полю врага
                //qDebug() << "enemy field: x= "<<pos.x()<<", y= "<< pos.y();
                enemy_field->set_point(pos,pole);}
            else ui->statusBar->showMessage("Сейчас не ваш ход!",2000);
        }


    }


//    QPoint pos = ev->pos();
//    pos.setY( pos.y() - this->centralWidget()->y() );
//    controller->onMousePressed( pos, ev->button() == Qt::LeftButton );
}

void MainWindow::redrow_func(int arr[FIELD_ROWS][FIELD_COLUMNS] ){
    if(GAME_status<CONNECTED_TO_SERVER){        
        GAME_status = GAME_START;
        ui->lable_Add_ships->setVisible(1);
        int arr_dinamic[FIELD_ROWS][FIELD_COLUMNS];
        int count_ships[4] = {4,3,2,1};
        for(int r(0); r<FIELD_ROWS; r++)
            for(int c(0); c<FIELD_COLUMNS; c++){
                //Lab[r][c]->setText("");
                Lab[r][c]->clear();
                arr_dinamic[r][c]=arr[r][c];}
        for(int r(0); r<FIELD_ROWS; r++)
            for(int c(0); c<FIELD_COLUMNS; c++){
                switch(arr_dinamic[r][c]){
                    case cell_ship1:{
                        //Lab[r][c]->setText("1");
                        Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+2,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35*1,35);
                        Lab[r][c]->setPixmap(ship1);
                        count_ships[0]--;

                    break;}

                    case cell_ship2:
                        //Lab[r][c]->setText("2");
                        if(arr_dinamic[r][c+1]==cell_ship2){ //horizontal
                            arr_dinamic[r][c+1]=cell_locked_to_print;
                            Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35*2,35);
                            Lab[r][c]->setPixmap(ship2_h);
                            count_ships[1]--;
                        }
                        else{//vertical
                            arr_dinamic[r+1][c]=cell_locked_to_print;
                            Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35,35*2);
                            Lab[r][c]->setPixmap(ship2_v);
                            count_ships[1]--;
                        }
                    break;

                    case cell_ship3:
                    if(arr_dinamic[r][c+1]==cell_ship3){ //horizontal
                        arr_dinamic[r][c+1]=cell_locked_to_print;
                        arr_dinamic[r][c+2]=cell_locked_to_print;
                        Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35*3,35);
                        Lab[r][c]->setPixmap(ship3_h);
                        count_ships[2]--;
                    }
                    else{//vertical
                        arr_dinamic[r+1][c]=cell_locked_to_print;
                        arr_dinamic[r+2][c]=cell_locked_to_print;
                        Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35,35*3);
                        Lab[r][c]->setPixmap(ship3_v);
                        count_ships[2]--;
                    }
                    //Lab[r][c]->setText("3");
                    break;

                    case cell_ship4:
                        //Lab[r][c]->setText("4");
                        if(arr_dinamic[r][c+1]==cell_ship4){ //horizontal
                            arr_dinamic[r][c+1]=cell_locked_to_print;
                            arr_dinamic[r][c+2]=cell_locked_to_print;
                            arr_dinamic[r][c+3]=cell_locked_to_print;
                            Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35*4,35);
                            Lab[r][c]->setPixmap(ship4_h);
                            count_ships[3]--;
                        }
                        else{//vertical
                            arr_dinamic[r+1][c]=cell_locked_to_print;
                            arr_dinamic[r+2][c]=cell_locked_to_print;
                            arr_dinamic[r+3][c]=cell_locked_to_print;
                            Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+0,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+20,35,35*4);
                            Lab[r][c]->setPixmap(ship4_v);
                            count_ships[3]--;
                        }
                    break;
                default: //qDebug() <<"redrow_func() case default;";
                    break;

                }
            }
        ui->num_ship1_my->setText("x"+QString::number(count_ships[0]));
        ui->num_ship2_my->setText("x"+QString::number(count_ships[1]));
        ui->num_ship3_my->setText("x"+QString::number(count_ships[2]));
        ui->num_ship4_my->setText("x"+QString::number(count_ships[3]));

        if(!count_ships[0] && !count_ships[1] && !count_ships[2] && !count_ships[3]){
            GAME_status = SHIPS_PLACED;
            ui->lable_Add_ships->setVisible(0);
        }
    }
    else ui->statusBar->showMessage("Игра началась!",2000);
}

void MainWindow::presettings(){
    //add custom fonts
    QFont font_dist(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11610.ttf")).at(0));
    QFont font_capture(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11653.otf")).at(0));
    QFont font_safron(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11662.ttf")).at(0));
    QFont font_better(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11665.otf")).at(0));
    QFont font_astakhov(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11668.ttf")).at(0));
    QFont font_astakhov_lab(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11668.ttf")).at(0));
    QFont danehand(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/my_fonts/11606.otf")).at(0));

    font_astakhov.setPointSize(11);
    danehand.setPointSize(14);
    font_safron.setPointSize(13);
    font_safron.setItalic(1);

    font_astakhov_lab.setPointSize(14);

    ui->statusBar->setFont(font_astakhov);

    ui->num_ship1_my->setFont(danehand);
    ui->num_ship2_my->setFont(danehand);
    ui->num_ship3_my->setFont(danehand);
    ui->num_ship4_my->setFont(danehand);

    ui->label->setFont(font_safron);

    ui->lable_Add_name->setFont(font_astakhov_lab);
    ui->lable_Add_ships->setFont(font_astakhov_lab);
    ui->lable_connect->setFont(font_astakhov_lab);


    //load icons
    ship1.load(":/images/ships/img/ship1.png");
    ship2_h.load(":/images/ships/img/ship2_h.png");
    ship2_v.load(":/images/ships/img/ship2_v.png");
    ship3_h.load(":/images/ships/img/ship3_h.png");
    ship3_v.load(":/images/ships/img/ship3_v.png");
    ship4_h.load(":/images/ships/img/ship4_h.png");
    ship4_v.load(":/images/ships/img/ship4_v.png");

    QPixmap bkgnd(":/images/img/pole2.png");
    QRegion exposed;
      bkgnd.scroll(0, 20, bkgnd.rect(), &exposed);
   // bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    /*this->setStyleSheet(
                "#centralWidget { "
                " background-image: url(:/images/pole2.png) 0 0 0 0 stretch stretch;"
                //" background-image: url(:/images/pole2.png) stretch;"
                "}");*/

    ui->butt_connect->setStyleSheet(
                "QPushButton{border-image: url(:/images/img/connect_unactive.png) stretch;}"
                "QPushButton:hover{border-image: url(:/images/img/connect_active.png) stretch;}"
                "QPushButton:pressed{border-image: url(:/images/img/connect_pressed.png) stretch;}");


    QFont f; f.setPointSize(15);//add items for ships
    for(int r(0); r<FIELD_ROWS; r++)
        for(int c(0); c<FIELD_COLUMNS; c++){
            Lab[r][c] = new QLabel(this);
            Lab[r][c]->setText("");

            Lab[r][c]->setFont(f);
            Lab[r][c]->setGeometry(FIELD_CELL_HIEGH*c+MY_FIELD_COORD_X+7,FIELD_CELL_WIDTH*r+MY_FIELD_COORD_Y+7,35,35);
            //Lab[r][c]->setGeometry(50,50,35,35);
            Lab[r][c]->show();
        }

    //ships info
    //ui->info_ship1_my->setPixmap(ship1);
    ui->info_ship2_my->setPixmap(ship2_h);
}


void MainWindow::on_action_journal_triggered(bool checked)
{
    if(checked)
        jrnl_list->show();
    else{
        jrnl_list->close();
    }
}
void MainWindow::close_journal(){
    ui->action_journal->setChecked(0);
}

void MainWindow::on_action_IP_triggered()
{
    enter_ip EI(this);// = new enter_ip(this);
    connect(&EI,&enter_ip::IP_changed_signal,this,&MainWindow::update_server_IP);

    EI.exec();
}
void MainWindow::update_server_IP(const QString& str){
    *HOST_IP = str;
}

void MainWindow::slot_send_com_to_serv(const int &i){
    enum commands{send_field=1};
    QByteArray Ba;
    switch (i) {
    case send_field:
        Ba.append(":field:");
        for(int r(0); r < FIELD_ROWS; r++)
            for(int c(0); c < FIELD_COLUMNS; c++)
                Ba.append(QString::number(my_field->map[r][c]));

        Ba.append(":");
        client->sock->write(Ba);

        break;
    default:
        break;
    }
}

void MainWindow::on_actionRestart_triggered()
{
    GAME_status=SHIPS_PLACED;
    ui->butt_connect->setStyleSheet("QPushButton{border-image: url(:/images/img/connect_unactive.png) stretch;}"
    "QPushButton:hover{border-image: url(:/images/img/connect_active.png) stretch;}"
    "QPushButton:pressed{border-image: url(:/images/img/connect_pressed.png) stretch;}");
    but_con_state=1;

    client->sock->abort();


    ui->line_name->setText("name");
    ui->line_password->setText("pass");
    ui->butt_connect->setEnabled(0);
    ui->lable_Add_name->setVisible(1);
    ui->lable_Add_ships->setVisible(1);
    ui->lable_connect->setVisible(1);

    my_field->clear();
}
