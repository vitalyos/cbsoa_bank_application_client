#ifndef JSONRESTUSERCLIENT_HPP
#define JSONRESTUSERCLIENT_HPP

#include "RestUserClient.hpp"

class JsonRestUserClient : public RestUserClient
{
public:
    ~JsonRestUserClient () = default;
    UserDto createUser (const UserDto & user) = 0;
    UserDto getUserById (const quint32 & id) = 0;
    QList<UserDto> getAllUsers () = 0;
    UserDto updateUser (const UserDto & user) = 0;
    bool deleteUser (const UserDto & user) = 0;
};

#endif // JSONRESTUSERCLIENT_HPP
