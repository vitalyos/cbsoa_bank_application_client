#ifndef RESTUSERCLIENT
#define RESTUSERCLIENT

#include "model/entity/UserDto.hpp"

#include <QList>

class RestUserClient {
public:
    virtual ~RestUserClient () = default;
    virtual UserDto createUser (const UserDto & user) = 0;
    virtual UserDto getUserById (const quint32 & id) = 0;
    virtual QList<UserDto> getAllUsers () = 0;
    virtual UserDto updateUser (const UserDto & user) = 0;
    virtual bool deleteUser (const UserDto & user) = 0;
};

#endif // RESTUSERCLIENT

