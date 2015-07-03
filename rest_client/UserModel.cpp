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
    m_getByIdManager= new QNetworkAccessManager(this);
    m_createManager = new QNetworkAccessManager(this);
    m_updateManager = new QNetworkAccessManager(this);
    m_deleteManager = new QNetworkAccessManager(this);

    connect(m_getAllManager, &QNetworkAccessManager::finished,this, &UserModel::parseGetAllResponse);
    connect(m_getByIdManager, &QNetworkAccessManager::finished, this, &UserModel::parseGetByIdResponse);
    connect(m_createManager, &QNetworkAccessManager::finished, this, &UserModel::parseCreateResponse);
    connect(m_updateManager, &QNetworkAccessManager::finished, this, &UserModel::parseUpdateResponse);
    connect(m_deleteManager, &QNetworkAccessManager::finished, this, &UserModel::parseDeleteResponse);

    connect(this, &UserModel::userListNeedToBeUpdated, this, &UserModel::userListRequired);
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

void UserModel::userListRequired()
{
    QUrl url(UserModel::s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    m_getAllManager->get(request);
}

void UserModel::deleteUser(const qint32 &id)
{
    QUrl url(UserModel::s_resourceName + "/" + QString::number(id));
    QNetworkRequest request;
    request.setUrl(url);
    m_deleteManager->deleteResource(request);
}

void UserModel::updateUser(UserDto *user)
{
    QUrl url(UserModel::s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_getAllManager->post(request, QJsonDocument(user->toJsonObject()).toJson());
}

void UserModel::createUser(UserDto *user)
{
    QUrl url(UserModel::s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_getAllManager->put(request, QJsonDocument(user->toJsonObject()).toJson());
}

void UserModel::parseGetAllResponse(QNetworkReply *response)
{
    UserList result;
    QByteArray data = response->readAll();
    qDebug () << "getAllResponse:" << data;
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &error);
    for (const auto & userObj : jsonDoc.array())
    {
        UserDto * user = new UserDto(this);
        user->fromJsonObject(userObj.toObject());
        result << user;
    }

    setUsers(qVariantFromValue(result));
}

void UserModel::parseGetByIdResponse(QNetworkReply *response)
{
    QByteArray data = response->readAll();
    qDebug () << "getByIdResponse:" << data;
}

void UserModel::parseCreateResponse(QNetworkReply *response)
{
    QByteArray data = response->readAll();
    qDebug () << "createResponse:" << data;

    emit userListRequired();
}

void UserModel::parseUpdateResponse(QNetworkReply *response)
{
    QByteArray data = response->readAll();
    qDebug () << "updateResponse:" << data;
    emit userListRequired();
}

void UserModel::parseDeleteResponse(QNetworkReply *response)
{
    qDebug () << "deleteResponse" << response->readAll();
    emit userListRequired();
}
