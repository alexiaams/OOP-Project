//
// Created by alexi on 5/25/2025.
//

#include "Admin.h"
#include<string>
#include <iostream>
#include <limits>
int Admin::passwordTries = 0;
bool Admin::login() const
{
    if (passwordTries==3)
    {
        std::cout << "You have been banned! \n";
        return false;
    }
    int input;
    std::cout<<"Enter password: ";
    std::cin>>input;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        passwordTries++;
        return false;
    }
    if(input==password)
    {
        std::cout<<" Login successful!\n";
        return true;
    }
    else
    {
        std::cout << "Login failed! \n";
        passwordTries++;
        return false;
    }
}