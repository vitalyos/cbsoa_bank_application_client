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
    emit requireCreateUser(user);
}

void UserController::updateUser(UserDto *user)
{
    emit requireUpdateUser(user);
}
