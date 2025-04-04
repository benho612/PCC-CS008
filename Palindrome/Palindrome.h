//
// Created by hoben on 2/21/2023.
//

#ifndef POINTERLAB_PALINDROME_H
#define POINTERLAB_PALINDROME_H
#include <string>

class Palindrome {
private:
    std::string string;
public:
    Palindrome();
    Palindrome(std::string word);
    bool isPalindrome();
    void changePhrase();

};


#endif //POINTERLAB_PALINDROME_H
