//
// Created by hoben on 3/28/2023.
//

#include "RPN.h"

double RPN::PostFixEval(const std::string& infix) {
    std::string postfix = InfixToPostfix(infix);
    std::stack<double> stack;
    double a,b;
    std::string tempNum;
     for (char i : postfix) {
        if(isOperator(i))
        {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(eval(b,a,i));
        }
        else if(isdigit(i))
        {
            tempNum.push_back(i);
        }
        else if(hasSpace(i))
        {
            stack.push(std::stod(tempNum));
            tempNum.clear();
        }

    }
    return stack.top();
}

bool RPN::isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return true;
    return false;
}

int RPN::priority(char ch) {
    if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '(' || ch == ')')
        return 0;
}

bool RPN::hasSpace(char ch) {
    if (ch == ' ')
        return true;
    else
        return false;
}


double RPN::eval(double left, double right, char op) {
    switch (op)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: return 0;
    }
}


std::string RPN::InfixToPostfix(const std::string& infix) {
    std::stack<char> stack;
    std::string temp;
    std::string tempNum;
    for (char i : infix) {
        if (isalnum(i))
        {
            tempNum.push_back(i);
        }
        else if (isOperator(i))
        {
            (!tempNum.empty()) ? temp.insert(temp.size(),tempNum + " ") : "";
            tempNum.clear();
            while (!stack.empty() && priority(i) <= priority(stack.top()))
            {
                temp.push_back(stack.top()); stack.pop();
            }
                stack.push(i);
        }
        else if (i == '(')
        {
            stack.push(i);
        }
        else if (i == ')')
            {
                (!tempNum.empty()) ? temp.insert(temp.size(),tempNum + " ") : "";
                tempNum.clear();
                while(stack.top() != '(')
                {
                    temp.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
    }
    (!tempNum.empty()) ? temp.insert(temp.size(),tempNum + " ") : "";
    while(!stack.empty())
    {
        temp.push_back(stack.top()); stack.pop();
    }

    return temp;
}


/// create a stack, and a queue
/// if number, push to a queue
/// if operator, then push to a stack
/// but if operator has higher priority than the stack.top,
/// then have to first pop the stack, and then push to the queue, then push to the stack.
/// if the operator is a " ) " , then pop stack, and push to the queue until find a " ( ".
/// if the operator is same priority, then pop stack and store in the queue until it found a low priority.