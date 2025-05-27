

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include <memory>

#include "Book.h"

class BookFactory
{
    public:
    static std::shared_ptr<Book> createBook(std::istream& is, int type);
};

#endif //BOOKFACTORY_H
