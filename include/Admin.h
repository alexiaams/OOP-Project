//
// Created by alexi on 5/25/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include <string>

class Admin
{   const std::string username = "admin";
    const int password=1234;
    static int passwordTries;
public:
    Admin()= default;
    bool login() const;
};
#endif //ADMIN_H
