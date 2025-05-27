

#ifndef POETRY_H
#define POETRY_H

#include "Book.h"

class Poetry : public Book
{
    const int poemCount;
public:
    Poetry(const std::string& name_, const std::string& author_, std::string genre_, int releaseYear_, int availableCopies_, int poemCount_);
    void display(std::ostream& os) const override;
};

#endif //POETRY_H
