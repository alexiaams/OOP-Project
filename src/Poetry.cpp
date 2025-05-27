

#include "Poetry.h"
#include <iostream>

Poetry::Poetry(const std::string& name_, const std::string& author_, std::string genre_, const int releaseYear_, const int availableCopies_, const int poemCount_):
Book(name_, author_, std::move(genre_), releaseYear_, availableCopies_), poemCount(poemCount_){}

void Poetry::display(std::ostream& os) const
{
    Book::display(os);
    os << " | Type: Poetry"
       << " | Poems: " << poemCount<< std::endl;
}