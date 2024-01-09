#include <fstream>
#include <iostream>
#include <string>
#include "User.h"
#include "AdminUser.h"
#include "RegularUser.h"

using namespace std;

void User::Register() {
    cout << "ENTER USER NAME : ";
    getline(cin, user_name);
    cout << "ENTER EMAIL ADDRESS( EMAIL SHOULD NOT CONTAIN ANY SAPCES ) : ";
    cin >> email;
    cout << "ENTER PASSWORD( PASSWORD SHOULD NOT CONTAIN ANY SAPCES ) : ";
    cin >> password;
    fstream file;
    file.open("user_data.txt", ios::out | ios::app);
    file << user_name << "*" << email << "*" << password << "\n";
    file.close();
    cout << "REGISTERED SUCESSFULLY !......\n";
    file.close();
}

void User::login() {
    string search_mail, search_password;
    cout << "ENTER EMAIL ADDRESS : ";
    cin >> search_mail;
    cout << "ENTER PASSWORD : ";
    cin >> search_password;
    fstream file;
    file.open("user_data.txt", ios::in);
    if (!file) {
        cout << "SORRY! NO RECORDS FOUND...........\n";
        return;
    }
    getline(file, user_name, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    int f = 0;
    while (!file.eof()) {
        if (email == search_mail && password == search_password) {
            cout << "LOGIN SUCESSFUL......\n\n";
            cout << "USER NAME : " << user_name << " || EMAIL : " << email
                 << endl;
            f = 1;
            break;
        }
        getline(file, user_name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (f == 0) {
        cout << "INVALID EMAIL/PASSWORD !.......\n";
    }
    file.close();
}

void User::forgetPassword() {
    string search_mail;
    cout << "ENTER EMAIL ADDRESS : ";
    cin >> search_mail;
    fstream file;
    file.open("user_data.txt", ios::in);
    if (!file) {
        cout << "SORRY! NO RECORDS FOUND...........\n";
        return;
    }
    getline(file, user_name, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    int f = 0;
    while (!file.eof()) {
        if (email == search_mail) {
            cout << "ACCOUNT FOUND ......\n\n";
            cout << "USER NAME : " << user_name << " || EMAIL : " << email
                 << "|| PASSWORD : " << password << endl;
            f = 1;
            break;
        }
        getline(file, user_name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (f == 0) {
        cout << "INVALID EMAIL !.......\n";
    }
    file.close();
}
