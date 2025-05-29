#include "InvalidNumber.h"

#include <stdexcept>
#include <string>

NumberException::NumberException(const std::string& msg): std::runtime_error(msg) {}

InvalidAge::InvalidAge(): NumberException("Invalid age. Please enter a positive number."){}

InvalidGrade::InvalidGrade(): NumberException("Invalid grade. Please enter a number between 1 and 12.") {}

InvalidChoice::InvalidChoice() : NumberException("Invalid choice. Please enter a number in the appropriate range.") {}

InvalidMonths::InvalidMonths(): NumberException("Invalid months. Please enter an integer >=1.") {}

InvalidNumber::InvalidNumber():NumberException("Please enter a number."){}