#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>
#include <iostream>

int main(int argc, char* argv[]) {




    nlohmann::json personJson;
    personJson["command"] = "deletePerson";
    personJson["FirstName"] = "Julian";
    personJson["LastName"] = "Jaksch";



    boost::asio::io_context service;
    unsigned short port = 3000;
    boost::asio::ip::tcp::endpoint server (boost::asio::ip::address::from_string ("127.0.0.1"), port);
    boost::asio::ip::tcp::socket sock (service);
    sock.connect (server);
    boost::asio::write (sock, boost::asio::buffer (personJson.dump (), personJson.dump ().length ()));
    std::cout << "Message was send!\n";




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
