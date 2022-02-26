#include "loginform.h"
#include "mainform.h"

LoginForm::LoginForm(QObject *parent) : Form(parent)
{
    connect(this, &LoginForm::token, this, &LoginForm::check_login);
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile tmp(path + "/token");
    if(tmp.exists()) {
        tmp.open(QIODevice::ReadOnly);
        emit token(tmp.readAll());
        tmp.close();
    }
    load(QUrl("qrc:/LoginForm.qml"));
    show();
}

void LoginForm::check_login(QString token)
{
    SotCom::SotCom* sotcom = new SotCom::SotCom(token, this);
    SotCom::Request* request = sotcom->get.send("me", {}, this);
    connect(request, &SotCom::Request::finished, this, &LoginForm::handle_response);
    request->send();
    //sotcom->deleteLater();
}

void LoginForm::handle_response(QJsonValue response)
{
    QString token = response.toObject().value("token").toString();
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if(!QDir(path).exists()) QDir().mkdir(path);
    QFile tmp(path + "/token");
    tmp.open(QIODevice::WriteOnly);
    tmp.write(token.toUtf8());
    tmp.close();
    ::sotcom = new SotCom::SotCom(token);


    new MainForm(response.toObject().toVariantMap());

    destroyWindow();
    deleteLater();
}
