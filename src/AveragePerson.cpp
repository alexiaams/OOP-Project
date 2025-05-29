#include "AveragePerson.h"
#include <iostream>
#include <limits>

#include "InvalidNumber.h"
AveragePerson::AveragePerson(std::string firstName_, std::string lastName_, int age_, std::string occupation_): Reader(std::move(firstName_), std::move(lastName_), age_), occupation(std::move(occupation_)) {}
double AveragePerson::membershipCost() const
{
    if (occupation=="teacher")
        return (membershipPrice-0.75*membershipPrice);
    if (occupation=="doctor")
        return membershipPrice-0.5*membershipPrice;
    if (age >=65)
        return membershipPrice-0.25*membershipPrice;
    return membershipPrice;
}

int AveragePerson::maxBooksAllowed(){ return 3;}
void AveragePerson::display(std::ostream& os) const
{
    os<<"ID: "<< getId()<< " Average person: "<<firstName<<" "<<lastName<<" age: "<<age<<" occupation: "<<occupation<<" \n";
}
void AveragePerson::readMore(std::istream& is)
{   std::cout<<"Enter occupation: ";
    std::getline(is >> std::ws, occupation);
    std::cout<<"Enter number of months for your membership: \n";
    while (true)
    {
        try
        {
            int months_;
            is>>months_;
            if (is.fail() || months_<1)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidMonths();
            }
            months=months_;
            break;
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
