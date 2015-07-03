#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include <QObject>
#include <QList>
#include <QVariant>

#include "model/entity/UserDto.hpp"

using UserList = QList<QObject*>;
class QNetworkAccessManager;
class QNetworkReply;

class UserModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant users READ users WRITE setUsers NOTIFY usersChanged)
public:
    explicit UserModel(QObject *parent = 0);
    ~UserModel ();

    QVariant users() const;
    void setUsers(const QVariant &users);

private:
    QVariant m_users;
    static QString s_resourceName;

    QNetworkAccessManager * m_getAllManager;
    QNetworkAccessManager * m_getByIdManager;
    QNetworkAccessManager * m_createManager;
    QNetworkAccessManager * m_updateManager;
    QNetworkAccessManager * m_deleteManager;
signals:
    void usersChanged ();
    void userListNeedToBeUpdated ();
public slots:
    void userListRequired ();
    void deleteUser (const qint32 &id);
    void updateUser (UserDto * user);
    void createUser (UserDto * user);

private slots:
    void parseGetAllResponse (QNetworkReply * response);
    void parseGetByIdResponse (QNetworkReply * response);
    void parseCreateResponse (QNetworkReply * response);
    void parseUpdateResponse (QNetworkReply * response);
    void parseDeleteResponse (QNetworkReply * response);
};

#endif // USERMODEL_HPP
