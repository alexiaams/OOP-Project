//
// Created by alexi on 5/25/2025.
//

#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H
#include "AveragePerson.h"
#include <string>
class PersonBuilder
{
    std::string firstName;
    std::string lastName;
    int age{};
public:
    PersonBuilder ();
    PersonBuilder& addFirstName(const std::string& firstName_);
    PersonBuilder& addLastName(const std::string& lastName_);
    PersonBuilder& addAge(int age_);
    AveragePerson build();
};
#endif //PERSONBUILDER_H
