#include "User.h"

User::User()
{
    //ctor
}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

User::~User()
{
    //dtor
}
