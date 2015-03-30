/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("iptr value: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("iptr value address: %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("iptr address: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 42;
    /*print the address of x*/
    printf("x addr: %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("x value: %d", x);
    
    return 0;
}
