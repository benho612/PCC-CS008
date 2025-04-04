#include "RPN.h"

int main() {
    std::cout << RPN::PostFixEval("1+1");
    std::cout <<"\n";
    std::cout << RPN::InfixToPostfix("1+1");
    std::cout <<"\n";
    std::cout << RPN::PostFixEval("3*6+7*(49/7)");
    std::cout <<"\n";
    std::cout << RPN::InfixToPostfix("3*6+7*(49/7)");

    //std::cout << RPN::InfixToPostfix("(3*6+(7*(49/7)-2))/2");
    return 0;
}
