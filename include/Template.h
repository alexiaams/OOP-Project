

#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Database
{
    std::vector<std::shared_ptr<T>> items;
public:
    void addItem(std::shared_ptr<T> item);
    bool removeItem(int itemId);
    void displayItems(std::ostream& os = std::cout);
    auto begin();
    auto end() ;
    const std::vector<std::shared_ptr<T>>& getItems() const;
    int size();
    std::shared_ptr<T> findId(int id);
};

template<typename T>
void Database<T>::addItem(std::shared_ptr<T> item) {items.push_back(std::move(item));}

template <typename T>
bool Database<T>::removeItem(int itemId)
{
    for (auto i=items.begin(); i!=items.end(); ++i)
    {
        if ((*i)->getId()==itemId)
        {
            items.erase(i);
            return true;
        }
    }
    return false;
}

template <typename T>
void Database<T>::displayItems(std::ostream& os)
{
    for (auto i=items.begin(); i!=items.end(); ++i)
        (*i)->display(os);
}
template <typename T>
int Database<T>::size() {return items.size();}

template <typename T>
std::shared_ptr<T> Database<T>::findId(int id)
{
    for (const auto& i : items)
        if (i->getId()==id)
            return i;

    return nullptr;
}
template <typename T>
auto Database<T> :: begin() {return items.begin();}

template <typename T>
auto Database<T>:: end() {return items.end();}

template <typename T>
const std::vector<std::shared_ptr<T>>& Database<T>::getItems() const {return items;};
#endif //TEMPLATE_H
