#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include <QObject>

class UserController : public QObject
{
    Q_OBJECT
public:
    explicit UserController(QObject *parent = 0);

signals:
    void requireDeleteUser (const qint32 &id);
public slots:
    void deleteUser (const qint32 &id);
};

#endif // USERCONTROLLER_HPP
