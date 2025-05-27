#include "BookFactory.h"
#include "Poetry.h"
#include<iostream>
#include <limits>

#include"Library.h"
#include "Novel.h"
#include "InvalidNumber.h"


std::shared_ptr<Book> BookFactory::createBook(std::istream& is, int type)
{
    std::string name_, author_, genre_;
    int releaseYear_, availableCopies_;

    std::cout<<"Enter book details: \n";
    std::cout<<"Name: ";
    std::getline(is >> std::ws, name_);
    std::cout<<"Author: ";
    std::getline(is >> std::ws, author_);
    std::cout<<"Genre: ";
    std::getline(is >> std::ws, genre_);
    while (true)
    {
        std::cout<<"Release Year: ";
        try
        {
            is>>releaseYear_;
            if (is.fail() || releaseYear_<=0)
            {
                is.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidNumber();
            }
            break;
        }catch (InvalidNumber& e)
        {
            std::cout<<e.what()<<"\n";
        }
    }

    if (type==1)
    {
        int poemCount_;
        std::cout<<"Enter poem count: ";
        is>>poemCount_;
        const auto book = std::make_shared<Poetry>(name_, author_, genre_, releaseYear_, availableCopies_, poemCount_);
        return book;
    }
    if (type==2)
    {
        int chapters_, pages_;
        std::cout<<"Enter chapters: ";
        is>>chapters_;
        std::cout<<"Enter pages: ";
        is>>pages_;
        const auto book = std::make_shared<Novel>(name_, author_, genre_, releaseYear_, availableCopies_, pages_, chapters_);
        return book;
    }
    return nullptr;
}
