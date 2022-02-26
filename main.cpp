#include <QApplication>


#include <QDebug>

#include "loginform.h"

#include <QtQml/QQmlApplicationEngine>
QQmlApplicationEngine* engine = nullptr;

#include "sotcom.h"
SotCom::SotCom* sotcom = nullptr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ::engine = &engine;

//    sotcom = new SotCom::SotCom("asd");
//    SotCom::Request* r = sotcom->get.send("me");
//    QObject::connect(r, &SotCom::Request::finished, [](QJsonValue rs) {
//        qDebug() << rs;
//    });
//    r->send();
    //r->deleteLater();

    new LoginForm;

    return app.exec();
}
