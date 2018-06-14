#include "field.h"
#include <QPoint>
#include <QDebug>

field::field(QObject *parent) : QObject(parent)
{
    clear();


}

bool field::other_ship_near(const int& row, const int&column){
    bool cant_push=0;
    //отлови баг. с размещением кораблей. иногда не дает поставить в угол, пишет что есть корабль рядом но это не так!
    if(row==0){
        if(column==0){
            if(map[row+1][column+1]!=0)
                cant_push=1;}
        else if(column==9){
            if(map[row+1][column-1]!=0)
                cant_push=1;}
        else{ if(map[row+1][column-1]!=0 || map[row+1][column+1]!=0)
                cant_push=1;}
    }
    else if(row==9){
        if(column==0){
            if(map[row-1][column+1]!=0)
                cant_push=1;}
        else if(column==9){
            if(map[row-1][column-1]!=0)
                cant_push=1;}
        else{ if(map[row-1][column-1]!=0 || map[row-1][column+1]!=0)
                cant_push=1;}
    }
    else {
        if(column==0){ if(map[row-1][column+1]!=0 || map[row+1][column+1]!=0)
                cant_push=1;}
        else if(column==9){ if(map[row-1][column-1]!=0 || map[row+1][column-1]!=0)
                cant_push=1;}
        else{ if(map[row-1][column-1]!=0 || map[row-1][column+1]!=0
                || map[row+1][column-1]!=0 || map[row+1][column+1]!=0)
            cant_push=1;}
    }

    if(cant_push){ qDebug() <<"cant set a ship. has other ship near!"; emit print_to_statusbar("Нельзя сюда! Рядом другой корабль!",4000);}
    return cant_push;
}

const QVector<cell_params_struct> field::cell_analysis(const int& row,const int& column){
    cell_params_struct cps;
    QVector<cell_params_struct> ship_arround_vect;

    if(column!=0 && map[row][column-1]!=0){
        cps.row=row;
        cps.column=column-1;
        cps.state=map[row][column-1];
        ship_arround_vect.push_back(cps);}

    if(column!=9 && map[row][column+1]!=0){
        cps.row=row;
        cps.column=column+1;
        cps.state=map[row][column+1];
        ship_arround_vect.push_back(cps);}

    if(row!=0 && map[row-1][column]!=0){
        cps.row=row-1;
        cps.column=column;
        cps.state=map[row-1][column];
        ship_arround_vect.push_back(cps);}

    if(row!=9 && map[row+1][column]!=0){
        cps.row=row+1;
        cps.column=column;
        cps.state=map[row+1][column];
        ship_arround_vect.push_back(cps);}



    return ship_arround_vect;
}

bool field::grade_ship_func(const QPoint& point,const QVector<cell_params_struct>& vec){
    //установка кораблей
    if(vec.size()==1){//если рядом один корабль
        switch(vec[0].state){
            case cell_ship1:
                if(Destroyer_ship){
                Destroyer_ship--;
                Boat_ship++;
                map[point.y()][point.x()] = cell_ship2;
                map[vec[0].row][vec[0].column] = cell_ship2;
                }
                else {emit print_to_statusbar("У вас больше нет Эсминцев!",2000); return 0;}
            break;
            case cell_ship2:
                if(Cruiser_ship){
                    Cruiser_ship--;
                    Destroyer_ship++;
                    map[point.y()][point.x()] = cell_ship3;
                    map[vec[0].row][vec[0].column] = cell_ship3;
                    if(vec[0].row == point.y()){
                        if(vec[0].column > point.x()) map[vec[0].row][vec[0].column+1] = cell_ship3;
                        else map[vec[0].row][vec[0].column-1] = cell_ship3;
                    }
                    else{
                        if(vec[0].row > point.y()) map[vec[0].row+1][vec[0].column] = cell_ship3;
                        else map[vec[0].row-1][vec[0].column] = cell_ship3;
                    }
                }
                else{ emit print_to_statusbar("У вас больше нет Крейсеров!",2000); return 0;}

            break;
            case cell_ship3:
                if(Linkor_ship){
                    Linkor_ship--;
                    Cruiser_ship++;
                    map[point.y()][point.x()] = cell_ship4;
                    map[vec[0].row][vec[0].column] = cell_ship4;
                    if(vec[0].row == point.y()){
                        if(vec[0].column > point.x()){
                            map[vec[0].row][vec[0].column+1] = cell_ship4;
                            map[vec[0].row][vec[0].column+2] = cell_ship4;
                        }
                        else {
                            map[vec[0].row][vec[0].column-1] = cell_ship4;
                            map[vec[0].row][vec[0].column-2] = cell_ship4;}
                    }
                    else{
                        if(vec[0].row > point.y()){
                            map[vec[0].row+1][vec[0].column] = cell_ship4;
                            map[vec[0].row+2][vec[0].column] = cell_ship4;
                        }
                        else {
                            map[vec[0].row-1][vec[0].column] = cell_ship4;
                            map[vec[0].row-2][vec[0].column] = cell_ship4;
                        }
                    }
                }
                else{ emit print_to_statusbar("У вас больше нет Линкора!",2000); return 0;}
            break;
        case cell_ship4: qDebug()<< "cant push here. Near Chip4!"; emit print_to_statusbar("Нельзя сюда! У Вас нет пятипалубных кораблей!",4000); return 0; break;
        default: qDebug()<<"!!ERROR! analyse_ships_rang_near(); vec.size()==1 vec[0].state>4 || vec[0].state<1"; return 0; break;
        }
    }


    else if(vec.size()==2){//если рядом 2 корабля
        switch ((vec[0].state+vec[1].state)) {
        case 2:
            if(Cruiser_ship){
            Cruiser_ship--;
            Boat_ship+=2;
            map[point.y()][point.x()] = cell_ship3;
            map[vec[0].row][vec[0].column] = cell_ship3;
            map[vec[1].row][vec[1].column] = cell_ship3;
            }
            else emit print_to_statusbar("У вас больше нет Крейсера!",2000);
            break;
        case 3:
            if(Linkor_ship){
            Linkor_ship--;
            Boat_ship++;
            Destroyer_ship++;

            map[point.y()][point.x()] = cell_ship4;
            for(int i(0); i<2; i++){
                if(vec[i].state==cell_ship1) map[vec[i].row][vec[i].column] = cell_ship4;
                else{
                    if(vec[i].row == point.y()){
                        if(vec[i].column>point.x()){
                            map[vec[i].row][vec[i].column] = cell_ship4;
                            map[vec[i].row][vec[i].column+1] = cell_ship4;
                        }
                        else{
                            map[vec[i].row][vec[i].column] = cell_ship4;
                            map[vec[i].row][vec[i].column-1] = cell_ship4;
                        }
                    }
                    else{
                        if(vec[i].row>point.y()){
                            map[vec[i].row][vec[i].column] = cell_ship4;
                            map[vec[i].row+1][vec[i].column] = cell_ship4;
                        }
                        else{
                            map[vec[i].row][vec[i].column] = cell_ship4;
                            map[vec[i].row-1][vec[i].column] = cell_ship4;
                        }
                    }
                }
            }
            } else emit print_to_statusbar("У вас больше нет Линкора!",2000);
            break;
        default:
            qDebug() << "Нельзя сюда ставить! У Вас нет пятипалубных кораблей!";
            emit print_to_statusbar("Нельзя сюда ставить! У Вас нет пятипалубных кораблей!",4000);
            return 0;
        }
    }
    else {qDebug() << "!! ERROR! analyse_ships_rang_near() vec.size!= 1 and != 2"; return 0;}
    return 1;
}

bool field::downgrade_ship_func(const QPoint& point,const QVector<cell_params_struct>& vec){
    //удаление(изменение) кораблей
    if(vec.size()==1){//если рядом один корабль
        if(vec[0].state==cell_ship2){
            if(Boat_ship){
                Boat_ship--;
                Destroyer_ship++;
                map[vec[0].row][vec[0].column] = cell_ship1;
                map[point.y()][point.x()] = cell_empty;
                return 1;
            }
            else{ emit print_to_statusbar("У вас нет доступных Лодок!",2000); return 0;}
        }
        if(point.y() == vec[0].row){//horizontal
            switch (vec[0].state) {
            case 3:
                if(Destroyer_ship){
                    Destroyer_ship--;
                    Cruiser_ship++;
                    map[point.y()][point.x()] = cell_empty;
                    if(point.x()>vec[0].column){
                        map[vec[0].row][vec[0].column] = cell_ship2;
                        map[vec[0].row][vec[0].column-1] = cell_ship2;
                    }
                    else{
                        map[vec[0].row][vec[0].column] = cell_ship2;
                        map[vec[0].row][vec[0].column+1] = cell_ship2;
                    }
                }
                else{ emit print_to_statusbar("У вас нет доступных Эсминцев!",2000); return 0;}
                break;
            case 4:
                if(Cruiser_ship){
                    Cruiser_ship--;
                    Linkor_ship++;
                    map[point.y()][point.x()] = cell_empty;
                    if(point.x()>vec[0].column){
                        map[vec[0].row][vec[0].column] = cell_ship3;
                        map[vec[0].row][vec[0].column-1] = cell_ship3;
                        map[vec[0].row][vec[0].column-2] = cell_ship3;
                    }
                    else{
                        map[vec[0].row][vec[0].column] = cell_ship3;
                        map[vec[0].row][vec[0].column+1] = cell_ship3;
                        map[vec[0].row][vec[0].column+2] = cell_ship3;
                    }
                }
                else{ emit print_to_statusbar("У вас нет доступных Крейсеров!",2000); return 0;}
                break;
            default:{qDebug() << "!! ERROR! downgrade_ship_func() case default"; return 0;}
            }
        }
        else{//vertical
            switch (vec[0].state) {
            case 3:
                if(Destroyer_ship){
                    Destroyer_ship--;
                    Cruiser_ship++;
                    map[point.y()][point.x()] = cell_empty;
                    if(point.y()>vec[0].row){
                        map[vec[0].row][vec[0].column] = cell_ship2;
                        map[vec[0].row-1][vec[0].column] = cell_ship2;
                    }
                    else{
                        map[vec[0].row][vec[0].column] = cell_ship2;
                        map[vec[0].row+1][vec[0].column] = cell_ship2;
                    }
                }
                else{ emit print_to_statusbar("У вас нет доступных Эсминцев!",2000); return 0;}
                break;
            case 4:
                if(Cruiser_ship){
                    Cruiser_ship--;
                    Linkor_ship++;
                    map[point.y()][point.x()] = cell_empty;
                    if(point.y()>vec[0].row){
                        map[vec[0].row][vec[0].column] = cell_ship3;
                        map[vec[0].row-1][vec[0].column] = cell_ship3;
                        map[vec[0].row-2][vec[0].column] = cell_ship3;
                    }
                    else{
                        map[vec[0].row][vec[0].column] = cell_ship3;
                        map[vec[0].row+1][vec[0].column] = cell_ship3;
                        map[vec[0].row+2][vec[0].column] = cell_ship3;
                    }
                }
                else{ emit print_to_statusbar("У вас нет доступных Крейсеров!",2000); return 0;}
                break;
            default:{qDebug() << "!! ERROR! downgrade_ship_func() case default"; return 0;}
            }
        }
    }

    else{//если два
        emit print_to_statusbar("НЕЛЬЗЯ удалять из середины!!",2000); return 0;
    }
    return 1;
}

void field::place_ship(const QPoint& pos){
    int row = pos.y();
    int column = pos.x();
    QString text;
    //int indx_map_r;
    switch(map[row][column]){
    case cell_empty:{//ячейка пуста
        ship_arround_vect = cell_analysis(row,column);//смотрим клетки вокруг
        int ship_arround_size = ship_arround_vect.size();
        if(!other_ship_near(row,column)){
            if(ship_arround_size==0){
                if(Boat_ship){
                    Boat_ship--;
                    map[row][column]=cell_ship1;
                    if(column<9) text = QString("Ship set: %1-%2").arg(QChar(0x410+column),QString::number(row+1));
                    else text = QString("Ship set: К-%1").arg(QString::number(row+1));
                    qDebug()<<text;
                    emit print_to_statusbar(text,1500);
                } else emit print_to_statusbar("У вас больше нет Лодок!",2000);
            }
            else if(ship_arround_size<3){
                if(grade_ship_func(pos,ship_arround_vect)){
                    if(column<9) text = QString("Ship add: %1-%2").arg(QChar(0x410+column),QString::number(row+1));
                    else text = QString("Ship add: К-%1").arg(QString::number(row+1));
                    qDebug()<<text;
                    emit print_to_statusbar(text,1500);
                }



            }
            else qDebug() << "!! ERROR! analyse_ships_rang_near() vec.size!= 1 and != 2";

        }
        break;}

    case cell_ship1:
        Boat_ship++;
        map[row][column]=cell_empty;

        if(column<9) text = QString("Ship del: %1-%2").arg(QChar(0x410+column),QString::number(row+1));
        else text = QString("Ship del: К-%1").arg(QString::number(row+1));
        qDebug()<<text;
        emit print_to_statusbar(text,1500);
        break;

    default://если не пустая и не однопалубный (переранжируем корабль)
        ship_arround_vect = cell_analysis(row,column);//смотрим клетки вокруг
        //int ship_arround_size = ship_arround_vect.size();
        if(downgrade_ship_func(pos,ship_arround_vect)){
            if(column<9) text = QString("Ship del: %1-%2").arg(QChar(0x410+column),QString::number(row+1));
            else text = QString("Ship del: К-%1").arg(QString::number(row+1));
            qDebug()<<text;
            emit print_to_statusbar(text,1500);
        }
        break;

    }

    //TODO обработка установки кораблей

    //emit redrow_field(&map[0]);

    print_field_debug();
    emit redrow_field(map);
}

void field::set_point(const QPoint& pos, const int& pole){

    switch(pole){
        case SHIPS_PLACED:{ //клик по своему полю
            QPoint point_MyField;
            point_MyField.setX((pos.x()-MY_FIELD_COORD_X)/FIELD_CELL_WIDTH);
            point_MyField.setY((pos.y()-MY_FIELD_COORD_Y)/FIELD_CELL_HIEGH);
            qDebug()<< "point_MyField row:" <<point_MyField.y() << ", column:"<<point_MyField.x();

            place_ship(point_MyField);
        break;
        }
        case YOU_TURN: //клик по полю противника

        break;

        default: break;
    }


}

void field::print_field_debug(){
    for(int i(0); i<FIELD_ROWS; i++)
            qDebug() <<"["<<map[i][0]<<" "<<map[i][1]<<" "<<map[i][2]<<" "<<map[i][3]<<" "<<map[i][4]<<" "<<map[i][5]<<" "<<map[6][0]<<" "<<map[i][7]<<" "<<map[i][8]<<" "<<map[i][9]<<"]";
}

void field::clear(){
    //clear mass
    for(int r(0); r<FIELD_ROWS; r++)
        for(int c(0); c<FIELD_COLUMNS; c++)
            map[r][c] = 0;

    //set default
    Boat_ship= 4;//4(1c)lodka
    Destroyer_ship = 3;//3(2c)esminec
    Cruiser_ship = 2;//2(3c)kreyser
    Linkor_ship = 1;//1(4c)linkor

    emit redrow_field(map);

}

