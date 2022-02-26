#include "addclientform.h"

AddClientForm::AddClientForm(QObject *parent) : Form(parent)
{
    load(QUrl("qrc:/AddClientForm.qml"));
}

void AddClientForm::newClient(QString firstname)
{
    //SotCom::Request* request = sotcom->send(SotCom::METHOD::PUT, "Client", {{"firstname",firstname}});
    //connect(request, &SotCom::Request::finishedWithRequest, this, &AddClientForm::response);
    //request->send();
    (void) firstname;
}

void AddClientForm::response(SotCom::Request* request, QJsonValue)
{
    request->deleteLater();
}
