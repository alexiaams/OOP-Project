
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Admin.h"
#include "Reader.h"
#include "Template.h"
#include "Book.h"

class Library
{   Database<Book> bookDb;
    Database<Reader> readerDb;
    Admin admin;
    Library() =default;
    static Library* instance;
public:
    static Library& getInstance();
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    ~Library() {delete instance;};

    void addData();
    void addReader(std::istream& is);
    void addBook(std::istream& is);
    void removeBook();
    void userMenu();
    bool adminMenu();
    void start();
    //bool stringInput(std::istream& is, std::string& input);
    void searchBook() const;
    std::shared_ptr<Reader> loginUser() const;
    void userMenu2(const std::shared_ptr<Reader>& user) const;
    static int validateChoice(std::istream& is, int min, int max);


};
#endif //LIBRARY_H
