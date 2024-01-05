void RegularUser::Register() {
    cout << "ENTER USER ID : ";
    getline(cin, user_id);
    cout << "ENTER USER NAME : ";
    getline(cin, user_name);
    cout << "ENTER EMAIL ADDRESS( EMAIL SHOULD NOT CONTAIN ANY SAPCES ) : ";
    cin >> email;
    cout << "ENTER PASSWORD( PASSWORD SHOULD NOT CONTAIN ANY SAPCES ) : ";
    cin >> password;
    fstream file;
    file.open("user_data_1.txt", ios::out | ios::app);
    file << user_id << "*" << user_name << "*" << email << "*" << password
         << "\n";
    file.close();
    cout << "REGISTERED SUCESSFULLY !......\n";
    file.close();
}
void RegularUser::login() {
    string search_id, search_mail, search_password;
    cout << "ENTER ID : ";
    cin >> search_id;
    cout << "ENTER EMAIL ADDRESS : ";
    cin >> search_mail;
    cout << "ENTER PASSWORD : ";
    cin >> search_password;
    fstream file;
    file.open("user_data_1.txt", ios::in);
    if (!file) {
        cout << "SORRY! NO RECORDS FOUND.........\n";
        return;
    }
    getline(file, user_id, '*');
    getline(file, user_name, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    int f = 0;
    while (!file.eof()) {
        if (user_id == search_id && email == search_mail &&
            password == search_password) {
            cout << "LOGIN SUCESSFUL......\n\n";
            cout << "USER NAME : " << user_name << " || EMAIL : " << email
                 << endl;
            f = 1;
            break;
        }
        getline(file, user_id, '*');
        getline(file, user_name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (f == 0) {
        cout << "INVALID EMAIL/PASSWORD !.......\n";
    }
    file.close();
}
void RegularUser::forgetPassword() {
    string search_id;
    cout << "ENTER USER ID : " << endl;
    cin >> search_id;
    fstream file;
    file.open("user_data_1.txt", ios::in);
    getline(file, user_id, '*');
    getline(file, user_name, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    int f = 0;
    while (!file.eof()) {
        if (user_id == search_id) {
            cout << "ACCOUNT FOUND ......\n\n";
            cout << "USER NAME : " << user_name << " || EMAIL : " << email
                 << endl;
            cout << "PASSWORD : " << password << endl;
            f = 1;
            break;
        }
        getline(file, user_id, '*');
        getline(file, user_name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (f == 0) {
        cout << "INVALID ID!.......\n";
    }
    file.close();
}
