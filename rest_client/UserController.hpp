#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include <QObject>
#include "model/entity/UserDto.hpp"

class UserController : public QObject
{
    Q_OBJECT
public:
    explicit UserController(QObject *parent = 0);

signals:
    void requireDeleteUser (const qint32 &id);
    void requireRefreshUserList ();
    void requireCreateUser (UserDto * user);
public slots:
    void deleteUser (const qint32 &id);
    void refreshUserList ();
    void createUser (UserDto * user);
};

#endif // USERCONTROLLER_HPP
