#ifndef USERDTO_HPP
#define USERDTO_HPP

#include <QObject>
#include <QString>
#include <QJsonObject>

class UserDto
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int userId READ id WRITE setId NOTIFY idChanged)
public:
    explicit UserDto(QObject *parent = 0);

    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);

    bool active() const;
    void setActive(bool active);

    void fromJsonObject (const QJsonObject &source);
    QJsonObject toJsonObject () const;

    qint32 id() const;
    void setId(const qint32 &id);

private:
    QString m_username;
    QString m_Password;
    QString m_error;
    qint32 m_id;
    bool m_active;

    static QString s_usernameKey;
    static QString s_passwordKey;
    static QString s_idKey;
    static QString s_activeKey;
    static QString s_errorKey;
signals:
    void usernameChanged ();
    void passwordChanged ();
    void idChanged ();
    void activeChanged ();
};

#endif // USERDTO_HPP
