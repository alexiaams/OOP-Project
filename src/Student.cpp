//
// Created by alexi on 5/25/2025.
//
#include "Student.h"
#include <iostream>

Student::Student(std::string firstName_, std::string lastName_, int age_, int grade_): Reader(std::move(firstName_), std::move(lastName_), age_), grade(grade_){}
int Student::membershipCost() const { return 10;}
int Student::maxBooksAllowed(){ return 5;}
void Student::display(std::ostream& os) const
{
    os<< "ID: "<<getId()<<" Student: "<<firstName<<" "<<lastName<<" grade: "<<grade<<" \n";
}
// void Student::readMore(std::istream& is)
// {
//     std::cout<<"Enter grade: ";
//     is>>grade;
// }
void Student::addReader(std::istream& is)
{   std::cout<<"student";
    Reader::addReader(is);

    std::cout<<"Enter grade: ";
    is>>grade;
}
