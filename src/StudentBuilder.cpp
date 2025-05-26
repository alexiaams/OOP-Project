
#include "StudentBuilder.h"
#include<string>
#include <iostream>


StudentBuilder::StudentBuilder()= default;
StudentBuilder& StudentBuilder::addFirstName(const std::string& firstName_)
{   firstName=firstName_;
    return *this;
}
StudentBuilder& StudentBuilder::addLastName(const std::string& lastName_)
{
    lastName=lastName_;
    return *this;
}
StudentBuilder& StudentBuilder::addAge(const int age_)
{
    age=age_;
    return *this;
}
StudentBuilder& StudentBuilder::addGrade(const int grade_)
{
    grade=grade_;
    return *this;
}
Student StudentBuilder::build()
{
    return {firstName, lastName, age, grade};
}
