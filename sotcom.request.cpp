#include <QJsonDocument>
#include <QtDebug>

#include "sotcom.request.h"

namespace SotCom {


Request::Request(Helper* helper, QString method, QJsonObject data, QObject *parent) :
    QObject (parent),
    helper(helper)
{
    QUrl url(SotCom::API_URL + method);
    request.setUrl(url);
    body = QJsonDocument(data).toJson(QJsonDocument::Compact);
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(body.size()));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("token", helper->sotcom->token.toUtf8());
}

void Request::send()
{
    QNetworkReply* reply = helper->sotcom->connection->sendCustomRequest(request, helper->verb.toUtf8(), body.toUtf8());
    connect(reply, &QNetworkReply::finished, [=](){ finish(reply); });
}

void Request::finish(QNetworkReply *reply)
{
    QString response = reply->readAll();
    if (reply->error()){
        QString err_str;
        if(response.isEmpty()) {
            err_str = reply->errorString();
        } else {
            err_str = QJsonDocument::fromJson(response.toUtf8()).object().value("err_str").toString();
        }
        emit error(err_str);
    } else {
        //qDebug() << response;
        QJsonValue result = QJsonDocument::fromJson(response.toUtf8()).object().value("result");
        emit finished(result);
        emit finishedWithRequest(this, result);
    }
    reply->deleteLater();
}

}
