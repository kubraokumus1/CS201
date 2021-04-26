//
// Created by User on 20.05.2020.
//

#include "AlgebraicExpression.h"

AlgebraicExpression::AlgebraicExpression() {
}

AlgebraicExpression::~AlgebraicExpression() {
}

string infix2prefix(string s) {
    string r = reverse(s);
    string postfix = infix2postfix(r);
    return reverse(postfix);
}

double evaluatePrefix(string s) {
    Stack stack = Stack();
    double first = 0;
    double second = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        switch (s[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                stack.push(s[i] - 48); // 48 is the ASCII value of '0' char,
                break;                          // I subtracted 48 from the value for accurate iteration
            case '+':
                stack.pop(first);
                stack.pop(second);
                stack.push(first+ second);
                break;
            case '-':
                stack.pop(first);
                stack.pop(second);
                stack.push(first - second);
                break;
            case '*':
                stack.pop(first);
                stack.pop(second);
                stack.push((first) * (second));

                break;
            case '/':
                stack.pop(first);
                stack.pop(second);
                stack.push((first) / (second));
                break;
        }

    }
    return stack.getTop();
}

string reverse(string s) {
    string r = "";
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '(')
            r = ')' + r;
        else if (s[i] == ')')
            r = '(' + r;
        else
            r = s[i] + r;
    }
    return r;
}

int precedence(double c) {
    if (c == '/' || (c == '*'))
        return 2;
    else if(c == '+' || (c == '-'))
        return 1;
    else
        return 0;
}

string infix2postfix(string s) {
    Stack stack = Stack();
    s = '(' + s + ')';
    string post = "";
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':    // append operand to end of PE
                post += s[i];
                break;
            case '(':        // save '(' on stack
                stack.push(s[i]);
                break;
            case ')':        // pop stack until matching '('
                while (stack.getTop() != '('){
                    post += stack.getTop();
                    stack.pop();
                }
                stack.pop();  // remove the open parenthesis
                break;
            case '+':
            case '-':
            case '*':
            case '/' :
                while (!stack.isEmpty() && stack.getTop() != '(' && precedence((double)s[i]) <= precedence(stack.getTop())){
                    post += stack.getTop();
                    stack.pop();
                }
                stack.push(s[i]); // save new operator
                break;

        }
    }
    return post;
}






