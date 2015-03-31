/* CS261- Assignment 0 - simple.c */
#include <stdio.h>

/* Name: Nathan Sosnovske
 * Date: 3/29/2015
 * Solution description: A simple C program that estimates pi using 1,000,000,000 iterations of a known sequence
 */


/*
 * Estimates pi using n iterations of 4(1 - 1/3 + 1/5 ... 1/(n+3))
 */
double EstimatePi(int iterations)
{
    double pi = 1;

    for(int i = 3; i < iterations * 2; i = i + 4)
    {
        pi = pi - (1.0/i) + (1.0/(i + 2.0));
    }

    return pi * 4;
};

int main()
{
    printf("Estimating pi using 1,000,000,000 iterations of summation 4(1 - 1/3 + 1/5 ... 1/(n+3))...\n");

    double pi = EstimatePi(1000000000);

    printf("%.15f\n", pi);

    return 0;
}