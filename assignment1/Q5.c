/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int MAX_LETTERS = 1000;

void sticky(char* word){
     /*Convert to sticky caps*/
     for(int i = 0; i < MAX_LETTERS; i++)
     {
         if(word[i] == '\0')
             return;

         if(i % 2)
             word[i] = tolower(word[i]);
         else
             word[i] = toupper(word[i]);
     }

}

int main(){
    /*Read word from the keyboard using scanf*/

    printf("Please enter a string: ");

    /* I'm using scanf because the spec calls for it... but it seems like a bad choice for user input
     * given that a buffer overflow is possible. Something like getchar() in a while loop or fgets might be
     * better?
     */

    char buffer[MAX_LETTERS];
    scanf("%s", buffer);
    /*Call sticky*/
    sticky(buffer);
    /*Print the new word*/
    printf("%s\n", buffer);
    
    return 0;
}
