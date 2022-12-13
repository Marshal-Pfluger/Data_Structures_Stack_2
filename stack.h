/*********************
 * Name:Marshal Pfluger
 * Coding 04
 * Purpose: This project takes what we learned
 * in coding 3 and upgrades the stack. implementing
 * dynamic memory allocation and passing by reference
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define
#define END 0
class Stack {

public:
    // Constructors
    Stack();

    //Destructors
    ~Stack();

    //Prototypes
    bool push(int, const string*);
    bool pop(Data*);
    bool peek(Data*);
    bool is_empty();

private:
    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H