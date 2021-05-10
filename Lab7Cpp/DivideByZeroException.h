#pragma once
#include <stdexcept>

class DivideByZeroException : public std::invalid_argument 
{
public:
	DivideByZeroException(const std::string& message);
	DivideByZeroException(const char* message);
	DivideByZeroException(const DivideByZeroException& other) noexcept;
};