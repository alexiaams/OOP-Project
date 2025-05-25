

#ifndef SEARCHBOOKS_H
#define SEARCHBOOKS_H
#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include <algorithm>
#include <functional>
#include <locale>
#include <cctype>

class SearchBooks
{
    // static std::string toLower(const std::string& str)
    // {
    //     std::string lowerStr;
    //     std::transform(str.begin(), str.end(), std::back_inserter(lowerStr),
    //                    [](const unsigned char c) { return std::tolower(c); });
    //     return lowerStr;
    // }
    static std::string toLower(const std::string& str)
    {   std::string newStr=str;
        transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
        return newStr;
    }
public:
    static std::vector<std::shared_ptr<Book>> searchByTitle(const std::vector<std::shared_ptr<Book>>& books, const std::string& title) ;
    static std::vector<std::shared_ptr<Book>> searchByAuthor(const std::vector<std::shared_ptr<Book>>& books, const std::string& author) ;
    static std::vector<std::shared_ptr<Book>> searchByGenre(const std::vector<std::shared_ptr<Book>>& books, const std::string& genre) ;
};

#endif //SEARCHBOOKS_H
