#ifndef MAINFORM_H
#define MAINFORM_H

#include <QObject>
#include <QVariantList>
#include <QJsonValue>

#include "form.h"

#include "sotcom.h"
#include "sotcom.request.h"
extern SotCom::SotCom* sotcom;

#include "ordersform.h"

class QQuickCloseEvent;

class MainForm : public Form
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap courier MEMBER courier NOTIFY courierChanged)
public:
    explicit MainForm(QVariantMap courier, QObject *parent = nullptr);
    QVariantMap courier;
    OrdersForm orders_form;

public slots:

    void openOrders();
    virtual void closing() override;

signals:
    void courierChanged();

};

#endif // MAINFORM_H
