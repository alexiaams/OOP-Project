//
// Created by alexi on 5/25/2025.
//
#include "AveragePerson.h"
#include <iostream>
AveragePerson::AveragePerson(std::string firstName_, std::string lastName_, int age_): Reader(std::move(firstName_), std::move(lastName_), age_){}
// int AveragePerson::membershipCost() const
// {
//     if (age<18)
//         return 0;
//     if (age <=25)
//         return 10;
//     if (age <=60)
//         return 20;
//     return 10;
// }
int AveragePerson::maxBooksAllowed(){ return 3;}
void AveragePerson::display(std::ostream& os) const
{
    os<<"ID: "<< getId()<< " Average person: "<<firstName<<" "<<lastName<<" age: "<<age<<" \n";
}
//void AveragePerson::readMore(std::istream& is) {};
void AveragePerson::addReader(std::istream& is)
{   std::cout<<"person";
    Reader::addReader(is);
    //readMore(is);
}
