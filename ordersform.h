#ifndef ORDERSFORM_H
#define ORDERSFORM_H

#include <QObject>

#include "form.h"

#include "sotcom.h"
#include "sotcom.request.h"
extern SotCom::SotCom* sotcom;

class OrdersForm : public Form
{
    Q_OBJECT
    Q_PROPERTY(QVariantList orders MEMBER orders NOTIFY ordersChanged)
public:
    explicit OrdersForm(QObject* parant = nullptr);
    QVariantList orders;
    SotCom::Request* orders_request;
signals:
    void ordersChanged();
public slots:
    void refresh();
    void handle_orders_request(QJsonValue response);
};

#endif // ORDERSFORM_H
