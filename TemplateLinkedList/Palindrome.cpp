//
// Created by hoben on 3/23/2023.
//
/*#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
bool isPalindrome(std::string& obj)
{
    for(int i=0; i<obj.size();i++)
    {
        if(!isalpha(obj[i]))
        {
            obj.erase(i,1);
        }
    }


    Stack<char> obj1;
    Queue<char> obj2;



    for(char i : obj)
    {
        obj1.push(tolower(i));
        obj2.push(tolower(i));

    }

    while(!(obj1.empty()) && !(obj2.empty()))
    {
        if (obj1.top() != obj2.front())
        {
            return false;
        }
        obj1.pop();
        obj2.pop();
    }
    return true;
}


int main()
{
    std::string test = "cat tac";
    if(isPalindrome(test))
        std::cout<<"It is palindrome";
    else
        std::cout<<"It is not palindrome";

}*/