
#include "PersonBuilder.h"
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
AveragePerson PersonBuilder::build()
{    //if(firstName==""||lastName==""||age==0)
    // throw eroare
    return {firstName, lastName, age};
}