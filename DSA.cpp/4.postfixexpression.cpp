// Evaluate Postfix Expression using Stack ADT.
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int performOperation(int operand1, int operand2, char operation) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }}

int evaluatePostfixExpression(const std::string& expression) {
    stack<int> stack;
    
    for (char c : expression) {
        if (isdigit(c)) {
            
            stack.push(c - '0');
        } else {
            
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            
            int result = performOperation(operand1, operand2, c);
            stack.push(result);
        }
    }
    
    return stack.top();
}

int main() {
    string expression = "23*4+10/2"; 
    int result = evaluatePostfixExpression(expression);
    cout << "Result of Postfix Expression \"" << expression << "\" is: " << result << std::endl;
    return 0;
}