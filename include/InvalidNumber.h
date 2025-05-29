
#ifndef INVALIDNUMBER_H
#define INVALIDNUMBER_H

#include <stdexcept>
#include <string>

class NumberException: public std::runtime_error
{
public:
    explicit NumberException(const std::string& msg);
    virtual ~NumberException() = default;
};

class InvalidNumber:public NumberException
{
    public:
    InvalidNumber();
};
class InvalidAge: public NumberException
{
public:
    InvalidAge();
};

class InvalidGrade: public NumberException
{
public:
    InvalidGrade();

};

class InvalidChoice:public NumberException
{
    public:
    InvalidChoice();
};

class InvalidMonths : public NumberException
{
public:
    InvalidMonths();
};

#endif //INVALIDNUMBER_H

