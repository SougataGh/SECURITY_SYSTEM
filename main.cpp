#include <fstream>
#include <iostream>
#include <string>
#include "User.h"
#include "AdminUser.h"
#include "RegularUser.h"
using namespace std;

int main() {
    User *user_ptr=new User;
    cout << "----------------------------------------------\n";
    cout << "1) REGISTER AS NORMAL USER \n";
    cout << "2) REGISTER AS REGULAR USER \n";
    cout << "3) LOGIN AS ADMIN \n";
    cout << "4) SHOW ALL USERS \n";
    cout << "5) LOGIN AS NORMAL USER \n";
    cout << "6) LOGIN AS REGULAR USER\n";
    cout << "7) FORGOT PASSWORD ( NORMAL USER )\n";
    cout << "8) REGULAR USER (REGULAR USER )\n";
    cout << "-----------------------------------------------\n";
    cout << "ENTER YOUR CHOICE :\n";
    char ch;
    cin >> ch;
    switch (ch) {
    case '1':
        cin.ignore();
       user_ptr->Register();
        break;
    case '2':
        user_ptr=new RegularUser;
        cin.ignore();
        user_ptr->Register();
        break;
    case '3':
        user_ptr=new  AdminUser;
        cin.ignore();
        user_ptr->login();
    case '4':
        user_ptr=new  AdminUser;
        cin.ignore();
        user_ptr->show_all_User();
        break;
    case '5':
        cin.ignore();
        user_ptr->login();
        break;
    case '6':
        user_ptr=new RegularUser;
        cin.ignore();
        user_ptr->login();
        break;
    case '7':
        cin.ignore();
        user_ptr->forgetPassword();
        break;
    case '8':
        user_ptr=new RegularUser;
        cin.ignore();
        user_ptr->forgetPassword();
        break;
    default:
        cout << "INVALID CHOICE!........\n";
        break;
    }
    return 0;
}
