#include "Library.h"
#include <iostream>
#include <limits>
#include <memory>
#include "Student.h"
#include "AveragePerson.h"
#include "Poetry.h"
#include "Novel.h"
#include "Reader.h"
#include "FilterBooks.h"
#include "PersonBuilder.h"
#include "StudentBuilder.h"
#include "Admin.h"
#include "Template.h"
#include "Book.h"

Library* Library::instance=nullptr;
Library& Library::getInstance()
{
    if (instance==nullptr)
        instance=new Library();
    return *instance;
}
int Library::validateChoice(const int min, const int max)
{
    int choice;
    while (true)
    {
        std::cin>>choice;
        if (std::cin.fail() || choice<min || choice>max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid choice! Please enter a number between "<<min<<" and "<<max<<" ( or press '0' to exit)\n";
        }
        else if (choice==0)
            return -1;
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}


void Library::addData()
{
    StudentBuilder builderS;
    PersonBuilder builderP;

    Student s1 = builderS.addFirstName("Alex").addLastName("Popescu").addAge(19).addGrade(11).build();
    Student s2 = builderS.addFirstName("Maria").addLastName("Ionescu").addAge(20).addGrade(12).build();

    AveragePerson p1 = builderP.addFirstName("Ana").addLastName("Marinescu").addAge(45).build();
    AveragePerson p2 = builderP.addFirstName("Mihai").addLastName("Popa").addAge(70).build();

    readerDb.addItem(std::make_shared<Student>(s1));
    readerDb.addItem(std::make_shared<Student>(s2));
    readerDb.addItem(std::make_shared<AveragePerson>(p1));
    readerDb.addItem(std::make_shared<AveragePerson>(p2));

    for (const auto& reader : readerDb )
        reader->display(std::cout);

    bookDb.addItem(std::make_shared<Poetry>("Luceafarul", "Mihai Eminescu", "Poezie romantica", 1883, 3, 98));
    bookDb.addItem(std::make_shared<Novel>("Harry Potter and the Philosopher's Stone ", "J.K Rowling", "Fantasy", 1997, 5, 320, 17));

}
void Library::removeBook()
{   std::cout<<"Enter the ID of the book you want to delete: \n";
    const int id=validateChoice( 1, bookDb.size());
    if (id==-1)
        return ;
    if (!bookDb.removeItem(id))
        std::cout<<"No book found with ID: "<<id<<std::endl;
    else
        std::cout<<"Book deleted! \n";
    for (const auto& i : bookDb )
        i->display(std::cout);
}

void Library::addReader(std::istream& is)
{
    int choice;
    std::shared_ptr<Reader> reader;
    while (true)
    {
        std::cout<<"Pick your membership:\n"
                   "1. Student \n"
                   "2. Normal Membership \n"
                   "3. Cancel\n";
        std::cin>>choice;
//chestie cautata pe google (Geeks for geeks)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid choice! Please choose 1 or 2\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            reader = std::make_shared<Student>(" ", " ", 0, 0);
            reader->addReader(is);
            break;
        case 2:
            reader = std::make_shared<AveragePerson>(" ", " ", 0);
            reader->addReader(is);
            break;
        case 3:
            return;
        default:
            std::cout<<"Invalid choice! Please choose 1 or 2\n";
            continue;
        }
        break;
    }
    readerDb.addItem(reader);
    for (const auto& i : readerDb )
        i->display(std::cout);

}
bool Library::adminMenu()
{
    if (admin.login())
    {
        int choice;
        while (true)
        {   std::cout<<"Hi admin! What do you want to do?\n";
            std::cout<<"1. Add book\n";
            std::cout<<"2. Remove book\n";
            std::cout<<"3. Display books\n";
            std::cout<<"4.Display readers\n";
            std::cout<<"5. Exit\n";
            std::cin>>choice;
            switch (choice)
            {
                case 1:
                    addBook(std::cin);
                    break;
                case 2:
                    removeBook();
                    break;
                case 3:
                    bookDb.displayItems();
                    break;
                case 4:
                    readerDb.displayItems();
                    break;
                case 5:
                    return true;
                default:
                    std::cout<<"Invalid input! Please choose 1, 2, 3, 4 or 5\n";
                    break;

            }
        }
    }
    else
        return false;
}
void Library::addBook(std::istream& is)
{
    std::string name_, author_, genre_;
    int releaseYear_, availableCopies_;
    std::cout<<"What do you want to add? (1 for Poetry and 2 for Novel)\n";
    const int type = validateChoice( 1, 2);
    if (type==-1)
        return;
    std::cout<<"Enter book details: \n";
    std::cout<<"Name: ";
    is>>name_;
    std::cout<<"Author: ";
    is>>author_;
    std::cout<<"Genre: ";
    is>>genre_;
    std::cout<<"Release Year: ";
    is>>releaseYear_;
    std::cout<<"Available Copies: ";
    is>>availableCopies_;
    if (type==1)
    {
        int poemCount_;
        std::cout<<"Enter poem count: ";
        is>>poemCount_;
        const auto book = std::make_shared<Poetry>(name_, author_, genre_, releaseYear_, availableCopies_, poemCount_);
        bookDb.addItem(book);
    }
    if (type==2)
    {
        int chapters_, pages_;
        std::cout<<"Enter chapters: ";
        is>>chapters_;
        std::cout<<"Enter pages: ";
        is>>pages_;
        const auto book = std::make_shared<Novel>(name_, author_, genre_, releaseYear_, availableCopies_, pages_, chapters_);
        bookDb.addItem(book);
    }

    for (const auto& i : bookDb )
        i->display(std::cout);

}
std::shared_ptr<Reader> Library::loginUser()
{
    std::cout<<"Enter your ID: ";
    int id;
    std::cin>>id;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid ID! \n";
        return nullptr;
    }
    if (auto user=readerDb.findId(id))
    {
        std::cout<<"Welcome"<<user->getFirstName()<<" "<<user->getLastName()<<"!\n";
        userMenu2(user);
        return user;
    }

    std::cout<<"No user found with ID: "<<id<<"\n";
    return nullptr;
}
void Library::userMenu()
{
    std::cout<<"=========================\n";
    std::cout<<"         USER MENU       \n";
    std::cout<<"=========================\n";
    std::cout<<"Do you already have a membership? (y/n)\n";
    std::string input;
    while (true)
    {
        std::cin>>input;
        if (input=="y" || input=="Y")
        {
            if (const auto user=loginUser())
                userMenu2(user);
            else
                std::cout<<"Login failed. Please try again or create a membership.\n";
            break;
        }
        if (input=="n" || input=="N")
         {
             addReader(std::cin);
             break;
         }
        else
            std::cout<<"Invalid input! Please enter 'y' or 'n'. \n"; //fa chestia sa tot ceara input pana dai corect ca esti incapabil si nu poti din prima
    }
}

void Library::userMenu2(const std::shared_ptr<Reader>& user)
{
    while (true)
    {
        std::cout<<"=========================\n";
        std::cout<<"         USER MENU       \n";
        std::cout<<"=========================\n";
        std::cout<<"1. Display books\n";
        std::cout<<"2. Display borrowed books\n";
        std::cout<<"3. Borrow a book \n";
        std::cout<<"4. Return a book\n";
        std::cout<<"5. Exit\n";
        std::cout<<"=========================\n";
        std::cout<<"What do you want to do?\n";
        int choice=validateChoice( 1, 5);
        switch (choice)
        {
        case 1:
            bookDb.displayItems();
            break;
        case 2:
            user->displayBorrowedBooks();
            break;
        case 3:
                while (true)
                {
                    std::cout<<"Sort by:\n 1. None \n 2.Name\n 3.Realease Year\n";
                    const int sortChoice=validateChoice(1, 3);
                    if (sortChoice==-1)
                        return;
                    if (sortChoice==1)
                        bookDb.displayItems();
                    else
                    { const SortBy by=(sortChoice==2)? SortBy::Name : SortBy::Year;
                        while (true)
                        {
                            std::cout<<"Press 'a' (for ascending), 'd' (for descending) or 'e' to exit.\n";
                            std::string input;
                            std::cin>>input;
                            if (input=="a" || input=="A")
                            {
                                std::vector<std::shared_ptr<Book>> sortedBooks=FilterBooks::filter(bookDb.getItems(), by, SortOrder::Ascending);
                                for (const auto& book : sortedBooks)
                                    book->display(std::cout);
                                break;
                            }
                            if (input=="d" || input=="D")
                            {
                                std::vector<std::shared_ptr<Book>> sortedBooks=FilterBooks::filter(bookDb.getItems(), by, SortOrder::Descending);
                                for (const auto& book : sortedBooks)
                                    book->display(std::cout);
                                break;
                            }
                            if (input=="e" || input=="E")
                            {
                                return;
                            }
                                std::cout<<"Invalid input! Please enter 'a', 'd' or 'e'. \n";
                        }
                    }
                std::cout<<"Enter the ID of the book you want to borrow: \n";
                    {
                        const int bookId=validateChoice( 1, bookDb.size());
                        if (bookId==-1)
                        return;
                    auto book=bookDb.findId(bookId);
                    user->borrowBook(book);
                }
                break;
            }
        case 4:
            {
                user->displayBorrowedBooks();
                std::cout<<"Enter ID of book to return: ";
                const int bookId=validateChoice(1, bookDb.size());
                if (bookId==-1)
                    return;
                auto book=bookDb.findId(bookId);
                user->returnBook(*book);
                break;
            }
        case 5:
            return;
        default:
            std::cout<<"Invalid input. Please choose a number between 1 and 5.\n";
            break;

        }
    }
}
void Library::start()
{   do {
        std::cout << "=========================\n";
        std::cout << "Welcome to the library!\n";
        std::cout << "=========================\n";
        std::cout << "1. Login user\n";
        std::cout << "2. Login admin\n";
        std::cout << "3. Exit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                userMenu();
                break;
            case 2:
                if(!adminMenu())
                    break;
                break;
            case 3:
                std::cout << "Have a nice day!!\n";
                return;
            default:
                std::cout << "Invalid input. Please choose a number between 1 and 3.\n";;
        }
    }while(true);
}
