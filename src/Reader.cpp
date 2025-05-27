#include "Reader.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <memory>

#include "InvalidNumber.h"


int Reader::totalReaders=0;
Reader::Reader(std::string firstName_, std::string  lastName_, const int age_): firstName(std::move(firstName_)), lastName(std::move(lastName_)), age(age_), readerId(++totalReaders), months(0)
{
    std::cout<<"reader id:"<<readerId<<std::endl;
}
Reader::Reader(const Reader& other): firstName(other.firstName), lastName(other.lastName), age(other.age), readerId(++totalReaders) {}
Reader& Reader::operator=(const Reader& other)
{
    firstName=other.firstName;
    lastName=other.lastName;
    age=other.age;
    months=other.months;
    return *this;
}
bool Reader::borrowBook(const std::shared_ptr<Book>&book)
{
    if (borrowedBooks.size()==static_cast<std::size_t>(maxBooksAllowed()))
    {
        std::cout<<"Borrow limit reached! \n";
        return false;
    }
    if (book->getAvailableCopies() <= 0 )
    {
        std::cout<<"Book not available! \n";
        return false;
    }

    borrowedBooks.push_back(book);
    --(*book);
    std::cout<<firstName<< " "<<lastName<<" borrowed"<<book->getName()<<std::endl;
    return true;
}
void Reader::addReader(std::istream& is)
{
    std::cout<<"Enter reader details: \n";
    std::cout<<"First name: ";
    std::getline(is >> std::ws, firstName);
    std::cout<<"Last name: ";
    std::getline(is >> std::ws, lastName);
    while (true)
    {
        std::cout<<"Age: ";
        try
        {
            is>>age;
            if (is.fail() || age<=0)
            {
                is.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidAge();
            }
            break;
        }catch (InvalidAge& e)
        {
            std::cout<<e.what()<<"\n";
        }
    }
}



void Reader::returnBook(Book& book)
{   bool found=false;
    for (auto i=borrowedBooks.begin(); i!=borrowedBooks.end(); ++i)
    {
        if ((*i)->getName()==book.getName())
        {   readBooks.push_back(*i);
            borrowedBooks.erase(i);
            ++book;
            std::cout<<firstName<< " "<<lastName<<" returned  "<<book.getName()<<std::endl;
            found=true;
            break;
        }
    }
    if (!found)
        std::cout<<"Book not found! \n";
}

void Reader::displayBorrowedBooks() const
{
    if (borrowedBooks.empty())
    {
        std::cout<<"No books borrowed! \n";
        return;
    }
    std::cout<<"Borrowed books: \n";
    for (const auto& book : borrowedBooks)
        book->display(std::cout);
}
std::ostream& operator<<(std::ostream& os, const Reader& reader)
{
    os<< "First name: "<<reader.firstName<<"\n Last name: "<<reader.lastName<<"\n Age:  "<<reader.age;
    return os;
}
std::istream& operator>>(std::istream& is, Reader& reader)
{   reader.addReader(is);
    return is;
}
int Reader:: getId() const { return readerId; }
//int Reader:: getMembershipCost() const { return membershipCost(); }
const std::string& Reader::getFirstName() const { return firstName; }
const std::string& Reader::getLastName() const { return lastName; }