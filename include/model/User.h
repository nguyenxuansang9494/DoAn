#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
    public:
        User();
        User(string username, string password);
        virtual ~User();

        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

    protected:

    private:
        string username;
        string password;
};

#endif // USER_H
