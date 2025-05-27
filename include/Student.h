
#ifndef STUDENT_H
#define STUDENT_H

#include "Reader.h"

class Student: public Reader
{
    int grade;
public:
    Student(std::string  firstName_, std::string  lastName_, int age_, int grade_);
    int membershipCost() const override;
    int maxBooksAllowed() override;
    void addReader(std::istream& is) override;
    void display(std::ostream& os) const override;
    void readMore(std::istream& is) override;

};

#endif //STUDENT_H
