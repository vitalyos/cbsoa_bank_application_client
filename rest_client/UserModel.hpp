#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include <QObject>
#include <QList>

#include "model/entity/UserDto.hpp"

using UserList = QList<UserDto*>;
class QNetworkAccessManager;
class QNetworkReply;

class UserModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(UserList users READ users WRITE setUsers NOTIFY usersChanged)
public:
    explicit UserModel(QObject *parent = 0);
    ~UserModel ();

    UserList users() const;
    void setUsers(const UserList &users);

private:
    UserList m_users;
    static QString s_resourceName;

    QNetworkAccessManager * m_getAllManager;
signals:
    void usersChanged ();
public slots:
    void userListRequred ();
    void deleteUser (const qint32 &id);
    void updateUser (UserDto * user);
    void createUser (UserDto * user);

private slots:
    void parseGetAllRequest (QNetworkReply * response);
};

#endif // USERMODEL_HPP
