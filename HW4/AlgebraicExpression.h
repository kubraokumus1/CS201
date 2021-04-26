//
// Created by User on 20.05.2020.
//

#ifndef HW4_ALGEBRAICEXPRESSION_H
#define HW4_ALGEBRAICEXPRESSION_H
#include <iostream>
#include "Stack.h"

using namespace std;

class AlgebraicExpression{
public:
    AlgebraicExpression();
    ~AlgebraicExpression();

};

string infix2postfix(string s);
string infix2prefix(string s);
double evaluatePrefix(string s);
string reverse(string s);
int precedence(double c);
#endif //HW4_ALGEBRAICEXPRESSION_H
