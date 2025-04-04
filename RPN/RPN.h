//
// Created by hoben on 3/28/2023.
//

#ifndef RPN_RPN_H
#define RPN_RPN_H
#include <iostream>
#include <stack>
#include <queue>

class RPN {
private:
public:
    static std::string InfixToPostfix(std::string infix);
    static double PostFixEval(std::string infix);
    static double eval(double left, double right, char op);
    static bool isOperator(char ch);
    static int priority(char ch);
    static bool hasSpace(char ch);


};


#endif //RPN_RPN_H
