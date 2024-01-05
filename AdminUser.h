class AdminUser : User {
public:
    AdminUser() {
        user_name = "Sougata Ghsoh";
        email = "ghoshsougataa@gmail.com";
        password = "Sougata@123";
    }
    void show_all_User();
    void login();
};
