#include "ordersform.h"

OrdersForm::OrdersForm(QObject* parent): Form(parent)
{
    load(QUrl("qrc:/OrdersForm.qml"));
    orders_request = sotcom->get.send("Orders", { {"district_id", 1} }, this);
    connect(orders_request, &SotCom::Request::finished, this, &OrdersForm::handle_orders_request);
    orders_request->send();
}

void OrdersForm::refresh()
{
    orders_request->send();
}

void OrdersForm::handle_orders_request(QJsonValue response)
{
    orders = response.toArray().toVariantList();
    emit ordersChanged();
}
