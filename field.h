#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QVector>
#include <defines.h>

enum cell_state{cell_empty=0, cell_ship1=1, cell_ship2=2, cell_ship3=3, cell_ship4=4, cell_locked_to_print=5};

class field : public QObject
{
    Q_OBJECT
public:
    explicit field(QObject *parent = nullptr);
    int map[FIELD_ROWS][FIELD_COLUMNS];

    void set_point(const QPoint& pos, const int &pole);
    void print_field_debug();
    void clear();

signals:
    void redrow_field(int arr[FIELD_ROWS][FIELD_COLUMNS]);
    void print_to_statusbar(const QString& str,int timeout);

public slots:
    void place_ship(const QPoint &pos);

private:
    short Boat_ship;//4(1c)lodka
    short Destroyer_ship;//3(2c)esminec
    short Cruiser_ship;//2(3c)kreyser
    short Linkor_ship;//1(4c)linkor


    QVector<cell_params_struct> ship_arround_vect;

    const QVector<cell_params_struct> cell_analysis(const int &row, const int &column);

    bool grade_ship_func(const QPoint &point, const QVector<cell_params_struct>& vec);
    bool downgrade_ship_func(const QPoint &point, const QVector<cell_params_struct>& vec);
    bool other_ship_near(const int& row, const int& column);



};

#endif // FIELD_H
