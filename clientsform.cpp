#include "clientsform.h"
#include "addclientform.h"

ClientsForm::ClientsForm(QObject *parent) : Form(parent)
{
    load(QUrl("qrc:/ClientsForm.qml"));
    close = false;
    //request = sotcom->send(SotCom::METHOD::GET, "Clients", {}, this);
    QObject::connect(request, &SotCom::Request::finished, this, &ClientsForm::getClients);
    request->send();
}


void ClientsForm::getClients(QJsonValue clients)
{
    this->clients = clients.toArray().toVariantList();
    emit clientsChanged();
}

void ClientsForm::newClient()
{
    swap(&addclientsform);
    //Form* temp = new AddClientForm(this);
    //swap_to(temp);
}

void ClientsForm::refresh()
{
    request->send();
}
