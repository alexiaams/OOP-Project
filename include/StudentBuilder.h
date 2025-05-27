

#ifndef STUDENTBUILDER_H
#define STUDENTBUILDER_H
#include "Student.h"
#include <string>
class StudentBuilder
{
    std::string firstName;
    std::string lastName;
    int age{};
    int grade{};
public:
    StudentBuilder();
    StudentBuilder& addFirstName(const std::string& firstName_);
    StudentBuilder& addLastName(const std::string& lastName_);
    StudentBuilder& addAge(int age_);
    StudentBuilder& addGrade(int grade_);
    Student build() ;
};
#endif //STUDENTBUILDER_H
