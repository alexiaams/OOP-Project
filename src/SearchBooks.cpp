#include "SearchBooks.h"
#include <locale>


// std::vector<std::shared_ptr<Book>> SearchBooks::searchByTitle(const std::vector<std::shared_ptr<Book>>& books, const std::string& title)
// {
//     std::vector<std::shared_ptr<Book>> temp;
//     const std::string lowerTitle=toLower(title);
//
//     for (const auto& book:books)
//         if (toLower(book->getName())==lowerTitle)
//             temp.push_back(book);
//     return temp;
// }
// std::vector<std::shared_ptr<Book>> SearchBooks::searchByAuthor(const std::vector<std::shared_ptr<Book>>& books, const std::string& author)
// {
//     std::vector<std::shared_ptr<Book>> temp;
//     const std::string LowerAuthor=toLower(author);
//     for (const auto& book:books)
//         if (toLower(book->getAuthor())==LowerAuthor)
//             temp.push_back(book);
//     return temp;
// }
// std::vector<std::shared_ptr<Book>> SearchBooks::searchByGenre(const std::vector<std::shared_ptr<Book>>& books, const std::string& genre)
// {
//     std::vector<std::shared_ptr<Book>> temp;
//     const std::string LowerGenre=toLower(genre);
//     for (const auto& book:books)
//         if (toLower(book->getGenre())==LowerGenre)
//             temp.push_back(book);
//     return temp;
// }

std::vector<std::shared_ptr<Book>> SearchBooks::searchAll(const std::vector<std::shared_ptr<Book>>& books, const std::string& searchTerm)
{
    std::vector<std::shared_ptr<Book>> temp;
    const std::string LowerSearchTerm=toLower(searchTerm);
    for (const auto& book:books)
        if (toLower(book->getName())==LowerSearchTerm || toLower(book->getAuthor())==LowerSearchTerm || toLower(book->getGenre())==LowerSearchTerm)
            temp.push_back(book);
    return temp;

}

