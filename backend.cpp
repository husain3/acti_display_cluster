#include "backend.h"

Backend::Backend() {


    // create a QUDP socket
    socket = new QUdpSocket(this);

    socket->bind(27151);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

QString Backend::doElse()
{
    QString str("arshad husain");
    return str;
}

QString Backend::doSome()
{
    // that's to demonstrate signal connection

    QString doElseRet = this->doElse();

    QByteArray newDoElse = doElseRet.toUtf8();

//    emit someThing(newDoElse);

    // simply returns a string with some markup
    return "<font color='green'>new <b>GREEN</b> thing</font>";
}

void Backend::readyRead() {
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    acti_payload_t* acti_pay = reinterpret_cast<acti_payload_t*>(buffer.data());

//    float f = acti_pay->RPM;
//    QByteArray array(reinterpret_cast<const char*>(&f), sizeof(f));

    QString f = QString::number(acti_pay->RPM);

    emit someThing(f);

    qDebug() << "Message from: " << acti_pay->RPM;
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
