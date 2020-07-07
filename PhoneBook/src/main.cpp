#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include "client.h"
#include "frontend.h"



int main(int argc, char* argv[]) {


    QCoreApplication::setAttribute (Qt::AA_EnableHighDpiScaling);


    QGuiApplication app (argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url (QStringLiteral ("../src/qml/main.qml"));
    QObject::connect (
    &engine, &QQmlApplicationEngine::objectCreated, &app,
    [url] (QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit (-1);
    },
    Qt::QueuedConnection);
    engine.load (url);
    return app.exec ();
}
