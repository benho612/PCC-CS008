//
// Created by hoben on 9/5/2023.
//

#ifndef CS8REVIEW_NEGATIVENUMBEREXCEPTION_H
#define CS8REVIEW_NEGATIVENUMBEREXCEPTION_H

#include <string>
#include <exception>

class NegativeNumberException: public std::exception {
private:
    std::string message;
public:
    NegativeNumberException();
    NegativeNumberException(const std::string & message);
    const char * what() const noexcept override;
};


#endif //CS8REVIEW_NEGATIVENUMBEREXCEPTION_H
