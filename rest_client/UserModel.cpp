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

QVariant UserModel::users() const
{
    return m_users;
}

void UserModel::setUsers(const QVariant &users)
{
    m_users = users;
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

    setUsers(qVariantFromValue(result));
}
