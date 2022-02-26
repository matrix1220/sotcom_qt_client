#ifndef SOTCOM_H
#define SOTCOM_H

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QtNetwork>

namespace SotCom {

class Request;
class SotCom;

class Helper : public QObject {
    Q_OBJECT
public:
    explicit Helper(QString verb, SotCom *parent = nullptr);
    SotCom* sotcom;
    QString verb;
    Request* send(QString method, QJsonObject data={}, QObject *parent = nullptr);
};

class SotCom : public QObject
{
    Q_OBJECT

public:

    explicit SotCom(QString token, QObject *parent = nullptr);
    QString token;

    Helper get;
    Helper post;

    QNetworkAccessManager* connection;

    void error(QString err_str);

    static const QString API_URL;

};

}

#endif // SOTCOM_H
