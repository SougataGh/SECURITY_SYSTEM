#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string user_name, email, password;

public:
    virtual void Register();
    virtual void login();
    virtual void forgetPassword();
};
