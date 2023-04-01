#include <stdio.h>
#include <iostream>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
const int prices[11] = {0 /*no price for length zero*/, 1,
                        5,
                        8, 9, 10, 17, 17, 20, 24, 30};

// cutRode in bottom-up fashion
// it typically depends on some natural notion of the "size" of a subproblem,
// such that solving ant particular subproblem depends only on solving
// "smaller" subproblems. Smaller subproblems must be solved first and thus
// their results are saved.
int cutRode(int store[], int remain)
{

    for (int i = 1; i <= remain; i++) // increase the length of the rode
    {
        int max_sum = 0;
        for (int j = 1; j <= i; j++) // increase the cut of the rode
        {
            // Question: why we can't use store[j]+prices[i-j] ?
            max_sum = MAX(max_sum, store[i - j] + prices[j]);
        }
        store[i] = max_sum; // save the result
    }
    return store[remain];
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