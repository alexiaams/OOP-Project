//
// Created by alexi on 5/25/2025.
//

#ifndef NOVEL_H
#define NOVEL_H

#include "Book.h"

class Novel : public Book
{
    const int pages;
    const int chapters;
public:
    Novel(std::string name_, const std::string& author_, std::string genre_, int releaseYear_, int availableCopies_, int pages_, int chapters_);
    void display(std::ostream& os) const override;
};
#endif //NOVEL_H
