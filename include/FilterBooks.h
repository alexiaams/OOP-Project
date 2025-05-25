
#ifndef FILTERBOOKS_H
#define FILTERBOOKS_H
#include<vector>
#include<memory>
#include "Book.h"

enum SortBy {Name,Year };
enum SortOrder {Ascending, Descending };

class FilterBooks
{
public:
    static std::vector<std::shared_ptr<Book>> filter(const std::vector<std::shared_ptr<Book>>& books, SortBy sortBy, SortOrder sortOrder);

};
#endif //FILTERBOOKS_H
