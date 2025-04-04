//
// Created by hoben on 9/5/2023.
//

#include "DivideByZeroException.h"

DivideByZeroException::DivideByZeroException() = default;

const char *DivideByZeroException::what() const noexcept {
    return message.c_str();
}

DivideByZeroException::DivideByZeroException(const std::string &message) {
    this -> message = message;
}
