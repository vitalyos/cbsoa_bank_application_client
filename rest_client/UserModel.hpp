#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include <QObject>

class UserModel : public QObject
{
    Q_OBJECT
public:
    explicit UserModel(QObject *parent = 0);

signals:

public slots:
};

#endif // USERMODEL_HPP
