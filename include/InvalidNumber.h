
#ifndef INVALIDNUMBER_H
#define INVALIDNUMBER_H

#include <stdexcept>
#include <string>

class InvalidNumber: public std::runtime_error
{
public:
    explicit InvalidNumber(const std::string& msg);
};

class InvalidAge: public InvalidNumber
{
public:
    InvalidAge();
};

class InvalidGrade: public InvalidNumber
{
public:
    InvalidGrade();

};

#endif //INVALIDNUMBER_H

