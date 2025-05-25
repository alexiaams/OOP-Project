//
// Created by alexi on 5/25/2025.
//

#include "Book.h"
#include <iostream>

int Book::id=0;
Book::Book(std::string name_, std::string  author_, std::string genre_, const int releaseYear_,
    const int availableCopies_): bookId(++id), name(std::move(name_)), author(std::move(author_)),
    genre(std::move(genre_)), releaseYear(releaseYear_), availableCopies(availableCopies_){}

int Book::getId() const { return bookId; }
std::string Book::getAuthor() const { return author; }
int Book::getAvailableCopies() const { return availableCopies; }
std::string Book::getGenre() const { return genre; }
int Book::getYear() const { return releaseYear; }
std::string Book::getName() const { return name; }

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

std::istream& operator>>(std::istream& in, Book& book)
{
    std::cout << "Book Name: ";
    in >> book.name;
    std::cout << "Author: ";
    in>>book.author;
    std::cout << "Genre: ";
    in>>book.genre;
    std::cout << "Release Year: ";
    in>>book.releaseYear;
    std::cout << "Available Copies: ";
    in>>book.availableCopies;
    return in;
}
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    book.display(os);
    return os;
}
void Book::borrow()
{
    if (availableCopies>0)
    {
        availableCopies--;
        std::cout<<"Book borrowed! \n";
    }
    else
    {
        availability=false;
        std::cout<<"No copies available! \n";
    }
}
void Book::returnB()
{
    availableCopies++;
    availability=true;
    std::cout<<"Book returned! \n";
}
