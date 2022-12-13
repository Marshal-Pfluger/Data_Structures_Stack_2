/*********************
 * Name:Marshal Pfluger
 * Coding 04
 * Purpose: This project takes what we learned
 * in coding 3 and upgrades the stack. implementing
 * dynamic memory allocation and passing by reference
**********************/

// each cpp includes ONLY it's header directly!

#include "stack.h"


Stack::Stack()
{
    top = -1;
}

// Destructor
Stack::~Stack()
{
    for(int i = top; i > 0; i--)
    {
        delete stack[i];
    }
}

// Module to insert data into stack
bool Stack::push(int id, const string* callData)
{
    bool status = false;
    if (top < STACK_SIZE - 1)
    {
        if(id > 0 && !callData->empty())
        {
            Data *dataBox = new Data;
            dataBox->id = id;
            dataBox->information = *callData;
            stack[++top] = dataBox;
            status = true;
        }
    }
    return status;
}

// Module to pop form stack
bool Stack::pop(Data *tempData)
{
    bool status = false;
    if(!is_empty())
    {
        tempData->id = stack[top]->id;
        tempData->information = stack[top]->information;
        delete stack[top];
        top--;
        status = true;
    }
    else
    {
        tempData->id = -1;
        tempData->information = "";
    }
    return status;
}

// Module to peek stack
bool Stack::peek(Data *tempData)
{
    bool status = false;
    if(!is_empty())
    {
        tempData->id = stack[top]->id;
        tempData->information = stack[top]->information;
        status = true;
    }
    else
    {
        tempData->id = -1;
        tempData->information = "";
    }
    return status;
}

// Module to check if stack is empty at location
bool Stack::is_empty()
{
    return top < END;
}