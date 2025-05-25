//
// Created by alexi on 5/25/2025.
//

#ifndef BOOK_H
#define BOOK_H
#include<string>

class Book
{
protected:
    int bookId;
    static int id;
    std::string name;
    std::string author;
    std::string genre;
    int releaseYear;
    bool availability= true;
    int availableCopies;
public:
    Book(std::string  name_, std::string  author_, std::string genre_, int releaseYear_, int availableCopies_);
    virtual ~Book()=default;
    //getters
    int getId() const;
    const std::string& getAuthor() const;
    const std::string& getName() const;
    int getYear() const;
    int getAvailableCopies() const;
    const std::string& getGenre() const;

    virtual void display(std::ostream& os) const;
    //void borrow();
    //void returnB();
    //overload
    Book& operator++();
    Book& operator--();

    friend std::istream& operator>>(std::istream& in, Book& book);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

};

#endif //BOOK_H
