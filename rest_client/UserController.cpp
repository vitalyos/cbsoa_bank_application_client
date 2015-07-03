#include "UserController.hpp"

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
