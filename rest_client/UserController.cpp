#include "UserController.hpp"
#include <QDebug>

UserController::UserController(QObject *parent) : QObject(parent)
{

}

void UserController::deleteUser(const qint32 &id)
{
    emit requireDeleteUser(id);
}

void UserController::refreshUserList()
{
    emit requireRefreshUserList();
}

void UserController::createUser(UserDto *user)
{
    qDebug () << "user" << user->username();
    emit requireCreateUser(user);
}
