#ifndef ADDCLIENTFORM_H
#define ADDCLIENTFORM_H

#include <QObject>

#include <QJsonValue>

#include "form.h"

#include "sotcom.h"
#include "sotcom.request.h"
extern SotCom::SotCom* sotcom;

class AddClientForm : public Form
{
    Q_OBJECT
public:
    explicit AddClientForm(QObject* parent=nullptr);
public slots:
    void newClient(QString firstname);
    void response(SotCom::Request*, QJsonValue);
};

#endif // ADDCLIENTFORM_H
