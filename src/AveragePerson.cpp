
#include "AveragePerson.h"
#include <iostream>
#include <limits>

#include "InvalidNumber.h"
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
    std::cout<<"Enter number of months for your membership: \n";
    while (true)
    {
        try
        {
            int months;
            is>>months;
            if (is.fail() || months<1)
            {
                is.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidMonths();
            }
        }
        catch (InvalidMonths& e)
        {
            std::cout<<e.what()<<"\n";
        }
    }
}


void AveragePerson::addReader(std::istream& is)
{
    Reader::addReader(is);
    readMore(is);
    std::cout<< "Membership cost: "<<membershipCost()<<" | Total to pay: "<<membershipCost()*months<<"\n";;
}
