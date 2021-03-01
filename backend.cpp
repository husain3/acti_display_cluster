#include "backend.h"

Backend::Backend() {

    // Create a QTCP Server to listen to ACTI Trigger Requests
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),
            this, SLOT(triggerRequestReadyRead()));
    if(!server->listen(QHostAddress::Any, 27150))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

    // Create a QUDP socket to listen to vehicle telemetry data
    socket = new QUdpSocket(this);
    socket->bind(27151);
    connect(socket, SIGNAL(readyRead()), this, SLOT(vehicleTelemReadyRead()));
}

void Backend::triggerRequestReadyRead() {
    QTcpSocket *socket = server->nextPendingConnection();

    QByteArray array;
    qint32 x = 5550;
    array.append((const char*)&x, sizeof(x));

    socket->write(array);
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();

    qDebug() << "Connect/Disconnect Trigger Handled";

}

void Backend::vehicleTelemReadyRead() {
    // when vehicle telemetry data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    acti_payload_t* acti_pay = reinterpret_cast<acti_payload_t*>(buffer.data());

    QString rpm = QString::number(acti_pay->RPM);
    QString speed = QString::number((int)acti_pay->SpeedKMH);
    QString gear = QString::number(acti_pay->gear);
    QString fuel = QString::number(acti_pay->fuel);

    emit displayData(rpm, speed, gear, fuel);

    qDebug() << "Fuel Rate: " << acti_pay->RPM / acti_pay->maxRpm / 10;
//    qDebug() << "Message port: " << senderPort;
//    qDebug() << "Message: " << buffer;
}
