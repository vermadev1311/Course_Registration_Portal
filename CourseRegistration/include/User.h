// User.h 
#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string id;
    std::string name;
    std::string email;
    std::string password;

public:
    User() {}
    User(const std::string &id_, const std::string &name_,
         const std::string &email_, const std::string &password_)
        : id(id_), name(name_), email(email_), password(password_) {}

    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

    bool checkPassword(const std::string &pass) const {
        return password == pass;
    }
};

#endif
