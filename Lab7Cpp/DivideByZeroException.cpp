#include "DivideByZeroException.h"

DivideByZeroException::DivideByZeroException(const std::string& message) : invalid_argument(message) {	}
DivideByZeroException::DivideByZeroException(const char* message) : invalid_argument(message) {	}
DivideByZeroException::DivideByZeroException(const DivideByZeroException& other) noexcept : invalid_argument(other) {	}