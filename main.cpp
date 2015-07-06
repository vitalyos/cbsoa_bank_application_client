#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "model/entity/UserDto.hpp"
#include "rest_client/UserController.hpp"
#include "rest_client/UserModel.hpp"
#include "model/entity/TransactionDto.hpp"
#include "rest_client/TransactionController.hpp"
#include "rest_client/TransactionModel.hpp"

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
    qmlRegisterType<TransactionDto>("edu.bbu.bank", 1, 0, "TransactionDto");
    qmlRegisterType<UserModel>("edu.bbu.bank", 1, 0, "UserModel");
    qmlRegisterType<TransactionModel>("edu.bbu.bank", 1, 0, "TransactionModel");
    qmlRegisterType<UserController>("edu.bbu.bank", 1, 0, "UserController");
    qmlRegisterType<TransactionController>("edu.bbu.bank", 1, 0, "TransactionController");
}
