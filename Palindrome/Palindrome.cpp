//
// Created by hoben on 2/21/2023.
//

#include "Palindrome.h"
#include <iostream>
Palindrome::Palindrome() {
}

Palindrome::Palindrome(std::string word):string(word) {
}

bool Palindrome::isPalindrome() {
    changePhrase();
    char *begin;
    begin = &string.at(0);
    char *end;
    end = &string.at(string.size()-1);
    while(begin < end)
    {
        if(*begin == *end)
        {
            begin++;
            end--;
        }
        else
            return false;
    }
    return true;
}

void Palindrome::changePhrase() {
    for(int i=0;i<string.size();i++)
    {
        if(!isalpha(string[i]))
        {
            string.erase(i,1);
        }
        else if(toupper(string[i]))
        {
            string[i] = tolower(string[i]);
        }
    }
}
