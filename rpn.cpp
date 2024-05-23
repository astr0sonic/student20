#include "rpn.h"
#include "bits/stdc++.h"
using namespace std;

bool isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double calculateRPN(const std::string& expr) {
    istringstream iss(expr);
    stack<double> stack;
    string token;
    while (iss >> token) {
        if (!isOperator(token)) {
            stack.push(std::stod(token));
        } else {
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                stack.push(operand1 / operand2);
            }
        }
    }
    return stack.top();
}
