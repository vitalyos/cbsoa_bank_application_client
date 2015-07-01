#include "UserDto.hpp"

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
quint64 UserDto::id() const
{
    return m_id;
}

void UserDto::setId(const quint64 &id)
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





