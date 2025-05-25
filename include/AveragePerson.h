//
// Created by alexi on 5/25/2025.
//

#ifndef AVERAGEPERSON_H
#define AVERAGEPERSON_H
#include "Reader.h"

class AveragePerson: public Reader
{
public:
    AveragePerson(std::string  firstName_, std::string  lastName_, int age_);
    int membershipCost() const override;
    int maxBooksAllowed() override;
    void display(std::ostream& os) const override;
    void addReader(std::istream& is) override;
    //void readMore(std::istream& is) override;
};

#endif //AVERAGEPERSON_H
