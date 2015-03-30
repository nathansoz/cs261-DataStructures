/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int minInclusive, int maxInclusive)
{
    int range = (maxInclusive - minInclusive + 1);
    return ((rand() % range) + minInclusive);
}

void printArray(int* intArray, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", intArray[i]);
    printf("\n");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void sort(int* number, int n){
     /*Sort the given array number , of length n*/

    // I was able to use the selection sort that I wrote in the past as part of a khan academy course...
    // you can find the c++ templated version here:
    //      https://github.com/nathansoz/KhanAcademy_Algorithms/blob/master/Khan_Algo/SelectionSort.h

    if (n == 0)
        return;

    for (int i = 0; i < n; i++) {
        int position = i;
        int minimumPos = i;

        for (int j = position; j < n; j++) {
            if (number[minimumPos] == number[j] || number[minimumPos] < number[j])
                continue;
            else
                minimumPos = j;
        }

        if (minimumPos != position)
            swap(&number[position], &number[minimumPos]);
    }
}



int main(){
    srand(time(NULL));

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int* intArray = malloc(sizeof(int) * n);

    /*Fill this array with random numbers, using rand().*/
    for(int i = 0; i < n; i++)
        intArray[i] = randInt(1, 100);
    
    /*Print the contents of the array.*/
    printArray(intArray, n);

    /*Pass this array along with n to the sort() function of part a.*/
    sort(intArray, n);
    
    /*Print the contents of the array.*/
    printArray(intArray, n);

    free(intArray);

    return 0;
}
