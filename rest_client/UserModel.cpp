#include "UserModel.hpp"

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QByteArray>
#include <QJsonParseError>

QString UserModel::s_resourceName = "http://localhost:51116/bank/api/users";

UserModel::UserModel(QObject *parent) : QObject(parent)
{
    m_getAllManager = new QNetworkAccessManager(this);

    QObject::connect(m_getAllManager, &QNetworkAccessManager::finished, this, &UserModel::parseGetAllRequest);
    userListRequred();
}

UserModel::~UserModel ()
{
    delete m_getAllManager;
}

UserList UserModel::users() const
{
    return m_users;
}

void UserModel::setUsers(const UserList &users)
{
    m_users = users;
    qDebug () << "got" << users.size() << "users";
    for (const auto & user : users)
    {
        qDebug () << "#" << user->id()
                  << "username" << user->username()
                  << ", password:" << user->password()
                  << ", active:" << user->active();
    }
    emit usersChanged();
}

void UserModel::userListRequred()
{
    QUrl url(UserModel::s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    m_getAllManager->get(request);
}

void UserModel::deleteUser(const qint32 &id)
{

}

void UserModel::updateUser(UserDto *user)
{

}

void UserModel::createUser(UserDto *user)
{

}

void UserModel::parseGetAllRequest(QNetworkReply *response)
{
    UserList result;
    QByteArray data = response->readAll();
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &error);
    qDebug () << "error:" << error.errorString();
    qDebug () << "read: " << data;
    qDebug () << "valid: " << jsonDoc.isArray();
    qDebug () << "converted back: " << jsonDoc.toJson();
    for (const auto & userObj : jsonDoc.array())
    {
        UserDto * user = new UserDto(this);
        user->fromJsonObject(userObj.toObject());
        result << user;
    }

    setUsers(result);
}
