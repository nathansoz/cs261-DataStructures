/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

const int NUM_STUDENTS = 10;

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students = malloc(sizeof(struct student) * NUM_STUDENTS);
     /*return the pointer*/
    return students;
}

int randInt(int minInclusive, int maxInclusive)
{
    int range = (maxInclusive - minInclusive + 1);
    return ((rand() % range) + minInclusive);
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     for(int i = 0; i < NUM_STUDENTS; i++)
     {
         students[i].id = i + 1;
         students[i].score = randInt(0, 100);
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }

    printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = -1;
    int max = -1;
    int total = 0;
    int average;

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        if(min > students[i].score || min == -1)
            min = students[i].score;
        if(max < students[i].score)
            max = students[i].score;

        total += students[i].score;
    }

    average = total / NUM_STUDENTS;

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Average: %d\n", average);

     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
