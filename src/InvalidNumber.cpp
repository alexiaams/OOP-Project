#include "InvalidNumber.h"

#include <stdexcept>
#include <string>

InvalidNumber::InvalidNumber(const std::string& msg) : std::runtime_error(" " + msg) {}

InvalidAge::InvalidAge(): InvalidNumber("Invalid age. Please enter a positive number."){}

InvalidGrade::InvalidGrade(): InvalidNumber("Invalid grade. Please enter a number between 1 and 12") {}

InvalidChoice::InvalidChoice() : InvalidNumber("Invalid choice. Please enter a number in the appropriate range.") {}

InvalidMonths::InvalidMonths(): InvalidNumber("Invalid months. Please enter an integer >=1") {}
