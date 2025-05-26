
#include "PersonBuilder.h"
#include <string>
PersonBuilder::PersonBuilder()= default;
PersonBuilder& PersonBuilder::addFirstName(const std::string& firstName_)
{   firstName=firstName_;
    return *this;
}
PersonBuilder& PersonBuilder::addLastName(const std::string& lastName_)
{
    lastName=lastName_;
    return *this;
}
PersonBuilder& PersonBuilder::addAge(const int age_)
{
    age=age_;
    return *this;
}
PersonBuilder& PersonBuilder::addOccupation(const std::string& occupation_)
{
    occupation=occupation_;
    return *this;
}
AveragePerson PersonBuilder::build()
{
    return {firstName, lastName, age,occupation };
}