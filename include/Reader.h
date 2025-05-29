
#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <memory>
#include "Book.h"

class Reader
{   protected:
    std::string firstName;
    std::string lastName;
    int age;
    const int readerId;
    static int totalReaders;
    int months{};
    const int membershipPrice=55;

    std::vector<std::shared_ptr<Book>> readBooks;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
public:
    Reader(std::string  firstName_, std::string  lastName_, int age_);
    Reader(const Reader& other);
    Reader& operator=(const Reader& other);
    int getId() const;
    virtual ~Reader()=default;
    virtual double membershipCost() const = 0;
    virtual int maxBooksAllowed()=0;
    //int getMembershipCost() const;
    virtual void display(std::ostream& os) const = 0;
    bool borrowBook(const std::shared_ptr<Book>&book);
    void returnBook(Book& book);
    virtual void addReader(std::istream& is);
    virtual void readMore(std::istream& is)= 0;
    friend std::ostream& operator<<(std::ostream& os, const Reader& reader);
    friend std::istream& operator>>(std::istream& is, Reader& reader);
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    void displayBorrowedBooks() const;
};

#endif //READER_H
