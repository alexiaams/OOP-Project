
#include "Student.h"
#include <iostream>
#include <limits>

#include "InvalidNumber.h"

Student::Student(std::string firstName_, std::string lastName_, const int age_, const int grade_): Reader(std::move(firstName_), std::move(lastName_), age_), grade(grade_){}

double Student::membershipCost() const
{
    if (grade<5)
        return 0;
    if (grade<9)
        return (membershipPrice-0.75*membershipPrice);
    return membershipPrice-0.5*membershipPrice;
}
int Student::maxBooksAllowed(){ return 5;}
void Student::display(std::ostream& os) const
{
    os<< "ID: "<<getId()<<" Student: "<<firstName<<" "<<lastName<<" grade: "<<grade<<" \n";
}
void Student::readMore(std::istream& is)
{
    while (true)
    {
        std::cout<<"Enter grade: ";
        try
        {
            is>>grade;
            if (is.fail() || grade<1 || grade>12)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidGrade();
            }
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        catch (InvalidGrade& e)
        {
            std::cout<<e.what()<<"\n";
        }
    }
    std::cout<<"Enter number of months for your membership: \n";
    while (true)
    {
        try
        {
            is>>months;
            if (is.fail() || months<1)
            {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidMonths();
            }
            break;
        }
        catch (InvalidMonths& e)
        {
            std::cout<<e.what()<<"\n";
        }
    }

}
void Student::addReader(std::istream& is)
{
    Reader::addReader(is);
    readMore(is);
    std::cout<< "Membership cost: "<<membershipCost()<<" | Total to pay: "<<membershipCost()*months<<"\n";
}
