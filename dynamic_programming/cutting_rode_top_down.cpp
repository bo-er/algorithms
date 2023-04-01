#include <stdio.h>
#include <iostream>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

const int prices[11] = {0 /*no price for length zero*/, 1,
                        5,
                        8, 9, 10, 17, 17, 20, 24, 30};

// cutrode is a top-down approach with memoization
// 1. checks to see if we have previously solved the problem
// 2.recursivly compute the value
// 3. save the value
int cutRode(int store[], int remain)
{
    // check whether optimal solution of cutting length:remain
    // rode has already been saved.
    if (store[remain] >= 0)
    {
        return store[remain];
    }

    // calculate the value
    int max_sum = -1;
    for (int i = 1; i <= remain; i++)
    {
        max_sum = MAX(max_sum, prices[i] + cutRode(store, remain - i));
    }

    // save the calculated value
    store[remain] = max_sum;
    return max_sum;
}

int main()
{
    int store[100];
    std::fill_n(store, 100, -1);
    store[0] = 0;
    store[1] = 1;
    for (int i = 1; i <= 10; i++)
    {
        printf("rode length: %d, total prices: %d\n", i, cutRode(store, i));
    }
}
