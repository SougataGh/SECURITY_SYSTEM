int main() {
    User u;
    AdminUser Adminu;
    RegularUser Regularu;
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
        u.Register();
        break;
    case '2':
        cin.ignore();
        Regularu.Register();
        break;
    case '3':
        cin.ignore();
        Adminu.login();
    case '4':
        cin.ignore();
        Adminu.show_all_User();
        break;
    case '5':
        cin.ignore();
        u.login();
        break;
    case '6':
        cin.ignore();
        Regularu.login();
        break;
    case '7':
        cin.ignore();
        u.forgetPassword();
        break;
    case '8':
        cin.ignore();
        Regularu.forgetPassword();
        break;
    default:
        cout << "INVALID CHOICE!........\n";
        break;
    }
    return 0;
}
