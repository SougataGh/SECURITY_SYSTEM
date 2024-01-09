#include <fstream>
#include <iostream>
#include <string>
#include "User.h"
#include "AdminUser.h"
#include "RegularUser.h"

using namespace std;

AdminUser::AdminUser() {
        user_name = "Sougata Ghsoh";
        email = "ghoshsougataa@gmail.com";
        password = "Sougata@123";
}

void AdminUser::login() {
    string email, password;
    cout << "ENTER EMAIL : ";
    cin >> email;
    cout << "ENTER PASSWORD : ";
    cin >> password;
    if (email == this->email && password == this->password) {
        cout << "ADMIN LOGIN SUCESSFUL!......\n";
    } else {
        cout << "ADMIN LOGIN UNSUCESSFUL!......\n";
        return;
    }
    cout << "DO YOU WANT TO SEE ALL THE USERS : [yes/no] \n";
    string str;
    cin >> str;
    if (str == "YES" || str == "Yes" || str == "yes") {
        show_all_User();
    }
}
void AdminUser::show_all_User() {
    string email, password;
    cout << "ENTER EMAIL : ";
    cin >> email;
    cout << "ENTER PASSWORD : ";
    cin >> password;
    if (email != this->email && password != this->password) {
        cout << "ADMIN LOGIN UNSUCESSFUL!......\n";
        return;
    }
    cout << "ADMIN LOGIN SUCESSFUL......\n";
    fstream file;
    file.open("user_data.txt", ios::in);
    if (!file) {
        cout << "NO RECORDS FOUND.........\n";
        return;
    }
    getline(file, user_name, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    while (!file.eof()) {
        cout << "USER NAME : " << user_name << endl;
        cout << "EMAIL : " << email << endl;
        cout << "PASSWORD : " << password << endl;
        cout << "-------------------------------------------\n";
        getline(file, user_name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    // file.close();
    file.close();
}
