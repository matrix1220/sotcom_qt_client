#ifndef FORM_H
#define FORM_H

#include <QObject>

#include <QQmlApplicationEngine>
extern QQmlApplicationEngine* engine;

#include <QQmlContext>
#include <QQmlComponent>
#include <QtQuick/QQuickWindow>

class Form : public QObject
{
    Q_OBJECT
public:
    explicit Form(QObject *parent = nullptr);

    QQmlContext context;
    QQmlComponent component;
    QQuickWindow* window = nullptr;

    Form* swaped_from = nullptr;
    bool close;

    void load(QUrl url);
    void setContext(QObject*);

    void swap_back();
    void swap(Form* form);

    void show();
    void hide();

    void destroyWindow();

signals:

public slots:
    void continueLoading();
    virtual void closing();
};

#endif // FORM_H
