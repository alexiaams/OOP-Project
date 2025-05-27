
#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H
#include "AveragePerson.h"
#include <string>
class PersonBuilder
{
    std::string firstName;
    std::string lastName;
    std::string occupation;
    int age{};
public:
    PersonBuilder ();
    PersonBuilder& addFirstName(const std::string& firstName_);
    PersonBuilder& addLastName(const std::string& lastName_);
    PersonBuilder& addAge(int age_);
    PersonBuilder& addOccupation(const std::string& occupation_);
    AveragePerson build();
};
#endif //PERSONBUILDER_H
