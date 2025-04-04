//
// Created by hoben on 9/5/2023.
//

#ifndef CS8REVIEW_DIVIDEBYZEROEXCEPTION_H
#define CS8REVIEW_DIVIDEBYZEROEXCEPTION_H

#include <exception>
#include <string>

class DivideByZeroException: public std::exception {
private:
    std::string message;
public:
    DivideByZeroException();
    DivideByZeroException(const std::string & message);
    const char * what() const noexcept override;
};


#endif //CS8REVIEW_DIVIDEBYZEROEXCEPTION_H
