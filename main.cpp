/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/

    Data *tempData = new Data;
    /*****************************************
     * Empty testing
     *****************************************/
    std::cout << "===================================" << std::endl;
    std::cout << "Testing empty functionality." << std::endl;
    std::cout << std::endl;
    Stack stack_obj1;
    if(stack_obj1.is_empty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is NOT empty" << std::endl;
    }

    // Checking pop() on empty stack.
    if(stack_obj1.pop(tempData))
    {
        std::cout << "Popped " << tempData->id << ":" << tempData->information << std::endl;
    }
    else
    {
        std::cout << "Pop underflow: Stack is empty" << std::endl;
    }

    // Checking peek() on empty stack.
    if(stack_obj1.peek(tempData))
    {
        std::cout << "Peeked " << tempData->id << ":" << tempData->information << std::endl;
    }
    else
    {
        std::cout << "Peek underflow: Stack is empty" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;

    /*****************************************
     * filling and full tests
     *****************************************/

    std::cout << "===================================" << std::endl;
    std::cout << "Filling to overflow." << std::endl;
    std::cout << std::endl;
    Stack stack_obj2;

    // Filling to overflow
    for (int i = 0; i < STACK_SIZE * MULTIPLIER; i++)
    {
        string dataInfo;
        if (i < number_test_cases)
        {
            dataInfo = data[i];
        }
        bool push_status = stack_obj2.push(ids[i], &dataInfo);
        if (push_status)
        {
            std::cout << "Element inserted " << ids[i] << ":" << data[i] << std::endl;
        }
        else
        {
            std::cout << "Stack overflow has occurred/empty string." << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "start current test" << std::endl;
    std::cout << "Checking empty at full" << std::endl;
    std::cout << std::endl;

    // Testing is empty on full stack
    if(stack_obj2.is_empty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is NOT empty" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "start current test" << std::endl;
    std::cout << "Checking peek and pop at full" << std::endl;
    std::cout << std::endl;

    // Checking peek() on full stack.
    if(stack_obj2.peek(tempData))
    {
        std::cout << "Peeked " << tempData->id << ":" << tempData->information << std::endl;
    }
    else
    {
        std::cout << "Peek underflow: Stack is empty" << std::endl;
    }

    // Checking pop() on full stack.
    if(stack_obj2.pop(tempData))
    {
        std::cout << "Popped " << tempData->id << ":" << tempData->information << std::endl;
    }
    else
    {
        std::cout << "Pop underflow: Stack is empty" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;

    /*****************************************
    * emptying tests
    *****************************************/

    std::cout << "start current test" << std::endl;
    std::cout << "peek and pop to underflow" << std::endl;
    std::cout << std::endl;

    //peeking and popping whole stack
    for (int i = 0; i < STACK_SIZE * MULTIPLIER; i++)
    {
        // Checking peek() whole stack.
        if(stack_obj2.peek(tempData))
        {
            std::cout << "Peeked " << tempData->id << ":" << tempData->information << std::endl;
        }
        else
        {
            std::cout << "Peek underflow: Stack is empty" << std::endl;
        }

        // Checking pop() whole stack.
        if(stack_obj2.pop(tempData))
        {
            std::cout << "Popped " << tempData->id << ":" << tempData->information << std::endl;
        }
        else
        {
            std::cout << "Pop underflow: Stack is empty" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;

    /*****************************************
     * peeking near middle.
     *****************************************/

    std::cout << "start current test" << std::endl;
    std::cout << "peeking near middle" << std::endl;
    std::cout << std::endl;

    Stack stack_obj3;
    for (int i = 0; i < STACK_SIZE / 2; i++)
    {
        string dataInfo;
        dataInfo = data[i];
        stack_obj3.push(ids[i], &dataInfo);
        if (stack_obj3.peek(tempData))
        {
            std::cout << "Peek " << tempData->id << tempData->information << std::endl;
        }
        else
        {
            std::cout << "Peek Underflow error has occurred/empty string." << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;

    /*****************************************
     * Random testing.
     *****************************************/

    std::cout << "start current test" << std::endl;
    std::cout << "Random testing" << std::endl;
    std::cout << std::endl;

     // filling stack to half to start random test
    Stack stack_obj4;
    for (int i = 0; i < STACK_SIZE / 2; i++)
    {
        string dataInfo;
        dataInfo = data[i];
        bool push_status = stack_obj2.push(ids[i], &dataInfo);
        if (push_status)
        {
            std::cout << "Element inserted " << ids[i] << ":" << data[i] << std::endl;
        }
        else
        {
            std::cout << "Stack overflow has occurred/empty string." << std::endl;
        }
    }
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_ATTEMPTS; i++) {

        switch (choice)
        {
            case 1:
            {
                case 2:
                {
                    // push
                    string dataInfo;
                    if (i < number_test_cases) {
                        dataInfo = data[i];
                    }
                    bool push_status = stack_obj4.push(ids[i], &dataInfo);
                    if (push_status) {
                        std::cout << "Element inserted " << ids[i] << ":" << data[i] << std::endl;
                    } else {
                        std::cout << "Stack overflow has occurred/empty string." << std::endl;
                    }
                }
            }
                break;
            case 3:
            {
                case 4:
                {
                    // pop
                    if (stack_obj2.pop(tempData)) {
                        std::cout << "Popped " << tempData->id << ":" << tempData->information << std::endl;
                    } else {
                        std::cout << "Pop underflow: Stack is empty" << std::endl;
                    }
                }
            }
                break;
            case 5:
            {
                // peek
                if (stack_obj2.peek(tempData)) {
                    std::cout << "Peeked " << tempData->id << ":" << tempData->information << std::endl;
                } else {
                    std::cout << "Peek underflow: Stack is empty" << std::endl;
                }
            }
                break;
            case 6:
            {
                // isempty
                if (stack_obj1.is_empty()) {
                    std::cout << "Stack is empty" << std::endl;
                } else {
                    std::cout << "Stack is NOT empty" << std::endl;
                }
            }
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    std::cout << std::endl;
    std::cout << "end current test" << std::endl;
    std::cout << "===================================" << std::endl;

    return 0;
}
