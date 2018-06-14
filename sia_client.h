#ifndef SIA_CLIENT_H
#define SIA_CLIENT_H

#include <QObject>
#include <QtNetwork>

class sia_client : public QObject
{
    Q_OBJECT
public:
    explicit sia_client(QObject *parent = nullptr);

    QTcpSocket *sock;

signals:
    void print_client_signal(const QString &str);
    void send_com_to_serv_signal(const int& i);

public slots:
    void slot_ready_read();
    void slot_sock_connected();
    void slot_sock_disconnected();
    void slot_sock_error(QAbstractSocket::SocketError err);
private:
    void parse_data(const QString &str);//парсим на стороне клиента
};

#endif // SIA_CLIENT_H
