#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "model/entity/UserDto.hpp"
#include "rest_client/UserController.hpp"
#include "rest_client/UserModel.hpp"

void registerTypes ();

int main(int argc, char *argv[])
{
    registerTypes();
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

void registerTypes()
{
    qmlRegisterType<UserDto>("edu.bbu.bank", 1, 0, "UserDto");
    qmlRegisterType<UserModel>("edu.bbu.bank", 1, 0, "UserModel");
    qmlRegisterType<UserController>("edu.bbu.bank", 1, 0, "UserController");
}
