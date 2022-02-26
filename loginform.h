#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "form.h"

#include <QObject>

#include "sotcom.h"
#include "sotcom.request.h"
extern SotCom::SotCom* sotcom;

class LoginForm : public Form
{
    Q_OBJECT
public:
    explicit LoginForm(QObject *parent = nullptr);

signals:
    void token(QString token);

public slots:
    void check_login(QString token);
    void handle_response(QJsonValue response);
};

#endif // LOGINFORM_H
