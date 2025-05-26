
#include "AveragePerson.h"
#include <iostream>
AveragePerson::AveragePerson(std::string firstName_, std::string lastName_, int age_, std::string occupation_): Reader(std::move(firstName_), std::move(lastName_), age_), occupation(std::move(occupation_)) {}
int AveragePerson::membershipCost() const
{
    if (occupation=="Teacher")
        return 20;
    if (occupation=="Doctor")
        return 25;
    return 45;
}

int AveragePerson::maxBooksAllowed(){ return 3;}
void AveragePerson::display(std::ostream& os) const
{
    os<<"ID: "<< getId()<< " Average person: "<<firstName<<" "<<lastName<<" age: "<<age<<"ocuppation: "<<occupation<<" \n";
}
void AveragePerson::readMore(std::istream& is)
{   std::cout<<"Enter ocupation: ";
    std::getline(is >> std::ws, occupation);
    int months;


};
void AveragePerson::addReader(std::istream& is)
{
    Reader::addReader(is);
    readMore(is);

}
