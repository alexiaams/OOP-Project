#include "FilterBooks.h"

#include <algorithm>


std::vector<std::shared_ptr<Book>> FilterBooks::filter(const std::vector<std::shared_ptr<Book>>& books, SortBy sortBy, SortOrder sortOrder)
{
    std::vector<std::shared_ptr<Book>> temp=books;
    switch (sortBy)
    {
    case SortBy::Name:
        if (sortOrder==SortOrder::Ascending)
            std::sort(temp.begin(), temp.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b)
                {return a->getName()<b->getName();});
        else
            std::sort(temp.begin(), temp.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b)
                {return a->getName()>b->getName();});
        break;
    case SortBy::Year:
        if (sortOrder==SortOrder::Ascending)
            std::sort(temp.begin(), temp.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b)
                {return a->getYear()<b->getYear();});
        else
            std::sort(temp.begin(), temp.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b)
                {return a->getYear()>b->getYear();});
        break;
    }
    return temp;

}
