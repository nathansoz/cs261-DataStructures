/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

int randInt(int minInclusive, int maxInclusive)
{
    int range = (maxInclusive - minInclusive + 1);
    return ((rand() % range) + minInclusive);
}

void generate(struct student* students, int n){
    /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    for(int i = 0; i < n; i++)
    {
        students[i].id = randInt(1, 10);
        students[i].score = randInt(0, 100);
    }
}

void output(struct student* students, int n){
    /*Output information about the ten students in the format:
             ID1 Score1
             ID2 score2
             ID3 score3
             ...
             ID10 score10*/

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }

    printf("\n");
}
void swap(struct student* a, struct student* b)
{
    struct student tmp = *a;
    *a = *b;
    *b = tmp;
}


void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    if (n == 0)
        return;

    for (int i = 0; i < n; i++) {
        int position = i;
        int minimumPos = i;

        for (int j = position; j < n; j++) {
            if (students[minimumPos].score == students[j].score ||
                    students[minimumPos].score < students[j].score)
                continue;
            else
                minimumPos = j;
        }

        if (minimumPos != position)
            swap(&students[position], &students[minimumPos]);
    }
}


int main(){

    srand(time(NULL));

    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(sizeof(struct student) * n);
    
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("Unsorted list: \n");
    output(students, n);

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("Sorted list: \n");
    output(students, n);

    free(students);
    
    return 0;
}
