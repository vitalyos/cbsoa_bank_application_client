#include "UserDto.hpp"

QString UserDto::s_usernameKey = "Username";
QString UserDto::s_passwordKey = "Password";
QString UserDto::s_activeKey = "Active";
QString UserDto::s_idKey = "Id";
QString UserDto::s_errorKey = "Error";

UserDto::UserDto(QObject *parent) : QObject(parent)
{

}

QString UserDto::username() const
{
    return m_username;
}

void UserDto::setUsername(const QString &username)
{
    m_username = username;
    emit usernameChanged();
}

QString UserDto::password() const
{
    return m_Password;
}

void UserDto::setPassword(const QString &password)
{
    m_Password = password;
    emit passwordChanged();
}

qint32 UserDto::id() const
{
    return m_id;
}

void UserDto::setId(const qint32 &id)
{
    m_id = id;
    emit idChanged();
}

bool UserDto::active() const
{
    return m_active;
}

void UserDto::setActive(bool active)
{
    m_active = active;
    emit activeChanged();
}

void UserDto::fromJsonObject(const QJsonObject &source)
{
    m_username = source[s_usernameKey].toString();
    m_Password = source[s_passwordKey].toString();
    m_active = source[s_activeKey].toBool();
    m_id = source[s_idKey].toInt();
    m_error = source[s_errorKey].toString();
}

QJsonObject UserDto::toJsonObject() const
{
    QJsonObject destination;
    destination.insert(s_usernameKey, m_username);
    destination.insert(s_passwordKey, m_Password);
    destination.insert(s_activeKey, m_active);
    destination.insert(s_idKey, m_id);
    return destination;
}
