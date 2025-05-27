#include "Novel.h"
#include <iostream>

Novel::Novel(std::string name_, const std::string& author_, std::string genre_, const int releaseYear_, const int availableCopies_, const int pages_, const int chapters_):
Book(std::move(name_), author_, std::move(genre_), releaseYear_, availableCopies_), pages(pages_), chapters(chapters_){}
void Novel::display(std::ostream& os) const
{
    Book::display(os);
    os << " | Type: Novel"
       << " | Pages: " << pages
       << " | Chapters: " << chapters << std::endl;
}