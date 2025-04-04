#include <iostream>
#include "Palindrome.h"
int main() {
    Palindrome word("Taco cat");
    if(word.isPalindrome())
        std::cout<<"is Palindrome" <<std::endl;
    else
        std::cout<<"not Palindrome" <<std::endl;


    return 0;
}
