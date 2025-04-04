//
// Created by hoben on 9/5/2023.
//

#include "NegativeNumberException.h"

NegativeNumberException::NegativeNumberException() = default;

NegativeNumberException::NegativeNumberException(const std::string &message) {
    this->message = message;
}

const char *NegativeNumberException::what() const noexcept {
    return message.c_str();
}
