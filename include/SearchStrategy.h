

#ifndef SEARCHBOOKS_H
#define SEARCHBOOKS_H
#include <string>
#include <vector>
#include <memory>
#include "Book.h"
#include <algorithm>
#include <locale>
#include <cctype>

class SearchStrategy
{
    virtual bool match(const std::shared_ptr<Book>& books, const std::string& searchTerm) = 0;
    protected:
    static std::string toLower(const std::string& str)
    {   std::string newStr=str;
        std::ranges::transform(newStr, newStr.begin(), ::tolower);
        return newStr;
    }
    public:
    virtual ~SearchStrategy()=default;
    virtual std::vector<std::shared_ptr<Book>>search(const std::vector<std::shared_ptr<Book>>& books,const std::string& searchTerm);

    // static std::vector<std::shared_ptr<Book>> searchByTitle(const std::vector<std::shared_ptr<Book>>& books, const std::string& title) ;
    // static std::vector<std::shared_ptr<Book>> searchByAuthor(const std::vector<std::shared_ptr<Book>>& books, const std::string& author) ;
    // static std::vector<std::shared_ptr<Book>> searchByGenre(const std::vector<std::shared_ptr<Book>>& books, const std::string& genre) ;
    //static std::vector<std::shared_ptr<Book>> searchAll(const std::vector<std::shared_ptr<Book>>& books, const std::string& searchTerm) ;
};
class SearchByName : public SearchStrategy
{
    bool match(const std::shared_ptr<Book>& books, const std::string& searchTerm) override;
};
class SearchByAuthor : public SearchStrategy
{
    bool match(const std::shared_ptr<Book>& books, const std::string& searchTerm) override;
};
class SearchByGenre : public SearchStrategy
{
    bool match(const std::shared_ptr<Book>& books, const std::string& searchTerm) override;
};
#endif //SEARCHBOOKS_H
