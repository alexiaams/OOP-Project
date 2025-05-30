

#include "Book.h"
#include <iostream>
#include <string>
int Book::id=0;
Book::Book(std::string name_, std::string  author_, std::string genre_, const int releaseYear_,
    const int availableCopies_): bookId(++id), name(std::move(name_)), author(std::move(author_)),
    genre(std::move(genre_)), releaseYear(releaseYear_), availableCopies(availableCopies_){}

int Book::getId() const { return bookId; }

int Book::getAvailableCopies() const { return availableCopies; }
const std::string& Book::getGenre() const { return genre; }
int Book::getYear() const { return releaseYear; }
const std::string& Book::getName() const { return name; }
const std::string& Book:: getAuthor() const{return author;}
Book& Book::operator++()
{
    ++availableCopies;
    availability=true;
    return *this;
}
Book& Book::operator--()
{
    if (availableCopies>0)
        --availableCopies;
    else
        availability=false;
    return *this;
}

void Book::display(std::ostream& os) const
{
    os << "Book ID: " << bookId
       << " | Title: " << name
       << " | Author: " << author
       << " | Genre: " << genre
       << " | Year: " << releaseYear
       << " | Available copies: " << availableCopies
       << std::endl;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    std::cout << "Book Name: ";
    std::getline(is >> std::ws, book.name);
    std::cout << "Author: ";
    std::getline(is >> std::ws, book.author); // asta cu ws e tot gasita pe geeks for geeks https://www.geeksforgeeks.org/problem-with-getline-after-cin/
    std::cout << "Genre: ";
    std::getline(is >> std::ws, book.genre);
    std::cout << "Release Year: ";
    is>>book.releaseYear;
    std::cout << "Available Copies: ";
    is>>book.availableCopies;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    book.display(os);
    return os;
}

