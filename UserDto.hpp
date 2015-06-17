#ifndef USERDTO_HPP
#define USERDTO_HPP

#include <QObject>
#include <QString>

class UserDto
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
public:
    explicit UserDto(QObject *parent = 0);

    QString username() const;
    void setUsername(const QString &username);

    QString Password() const;
    void setPassword(const QString &Password);

    quint64 id() const;
    void setId(const quint64 &id);

    bool active() const;
    void setActive(bool active);

private:
    QString m_username;
    QString m_Password;
    quint64 m_id;
    bool m_active;
signals:
    void usernameChanged ();
    void passworChanged ();
    void idChanged ();
    void activeChanged ();
};

#endif // USERDTO_HPP
