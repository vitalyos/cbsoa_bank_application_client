#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include <QObject>

class UserController : public QObject
{
    Q_OBJECT
public:
    explicit UserController(QObject *parent = 0);

signals:

public slots:
};

#endif // USERCONTROLLER_HPP
