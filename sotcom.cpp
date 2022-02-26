#include "sotcom.h"
#include "sotcom.request.h"
#include "errorform.h"

namespace SotCom {

//const QString SotCom::API_URL("http://127.0.0.1:5000/");
const QString SotCom::API_URL("http://192.168.1.164:5000/");

SotCom::SotCom(QString token, QObject *parent) :
    QObject(parent),
    token(token),
    get("GET", this),
    post("POST", this)
{
    connection = new QNetworkAccessManager(this);
}


void SotCom::error(QString err_str)
{
    ErrorForm* form = new ErrorForm(err_str, this);
    form->show();
}

Helper::Helper(QString verb, SotCom *parent): QObject(parent), sotcom(parent), verb(verb)
{
}

Request *Helper::send(QString method, QJsonObject data, QObject *parent)
{
    return new Request(this, method, data, parent);
}

}
