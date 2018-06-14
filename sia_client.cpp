#include "sia_client.h"
#include "mainwindow.h"

sia_client::sia_client(QObject *parent) : QObject(parent),
    sock(new QTcpSocket(this))
{

}

void sia_client::slot_sock_error(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(sock->errorString())
                    );
   //m_ptxtInfo->append(strError);
   // qDebug() << strError;
    emit print_client_signal("|connect|: " + strError);
}

void sia_client::slot_ready_read(){
    QString str = sock->readAll();
    emit print_client_signal("|client|: Get data from server:\n" + str);
    parse_data(str);
}
void sia_client::parse_data(const QString &str){
    QRegExp rx(":(\\w+):");
    if(rx.indexIn(str)!=1){//если комманда
        //qDebug() << rx.cap(1);
        if(rx.cap(1) == "connect"){//:connect:identificator:
            QRegExp con(":connect:(\\d+):");
            con.indexIn(str);
            emit print_client_signal("identificator = " + con.cap(1));
            emit send_com_to_serv_signal(1); //1 - отправить поле на сервер

        }
        /*else if(rx.cap(1) == "field"){//:field:bitmap:
            QRegExp fld(":field:(\\d):");
            fld.indexIn(str);
            qDebug() << fld.cap(1);

        }*/
    }

}
void sia_client::slot_sock_connected(){
    emit print_client_signal("|client|: Connect to server successfully");
}
void sia_client::slot_sock_disconnected(){
    emit print_client_signal("|client|: Disconnect from server");
}
