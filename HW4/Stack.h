//
// Created by User on 20.05.2020.
//

#ifndef HW4_STACK_H
#define HW4_STACK_H

#include <iostream>
class Stack{

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(double newItem);
    bool pop();
    bool pop(double & stackTop);
    bool getTop(double& stackTop) const;
    double getTop();

private:
    struct StackNode {
        double item;
        StackNode  *next;
    };

    StackNode *topPtr;
};
#endif //HW4_STACK_H
