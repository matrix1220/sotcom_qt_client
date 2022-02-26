#include "mainform.h"
#include <QApplication>

MainForm::MainForm(QVariantMap courier, QObject *parent) : Form(parent), courier(courier)
{
    load(QUrl("qrc:/MainForm.qml"));
    show();
    //emit courierChanged();
}

void MainForm::openOrders()
{
    swap(&orders_form);
}

void MainForm::closing()
{
    Form::closing();
    QApplication::exit();
}


