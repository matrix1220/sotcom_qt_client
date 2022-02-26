#ifndef CLIENTSFORM_H
#define CLIENTSFORM_H

#include <QObject>
#include <QVariantList>
#include <QJsonValue>

#include "form.h"

#include "addclientform.h"

#include "sotcom.h"
#include "sotcom.request.h"
extern SotCom::SotCom* sotcom;

class ClientsForm : public Form
{
    Q_OBJECT
public:
    explicit ClientsForm(QObject *parent = nullptr);
    Q_PROPERTY(QVariantList clients MEMBER clients NOTIFY clientsChanged)

    SotCom::Request* request;

    QVariantList clients;

    AddClientForm addclientsform;

public slots:
    void getClients(QJsonValue); // make private this
    void newClient();
    void refresh();

signals:
    void clientsChanged();
};

#endif // CLIENTSFORM_H
