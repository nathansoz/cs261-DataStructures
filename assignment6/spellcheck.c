#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht);

char* getFileName();

int main (int argc, const char * argv[]) {
  clock_t timer;
  int tableSize = 1000;
  struct hashMap* hashTable = createMap(tableSize);

  char* fileName = getFileName();

  timer = clock();
  FILE* dictionary = fopen(fileName, "r");
  
  if (dictionary == NULL)
  {
	  printf("No file %s exists!", fileName);
	  free(fileName);
	  return 1;
  }
  else
	  free(fileName);

  loadDictionary(dictionary,hashTable);
  timer = clock() - timer;
	printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
  
  char* word = (char*)malloc(256*sizeof(char));
  int quit=0;
  while(!quit){
    printf("Enter a word: ");
    scanf("%s",word);
    
	/*ensure we have lowercase input*/
	size_t i;
	for (i = 0; i < strlen(word); i++)
		word[i] = tolower(word[i]);

	if (atMap(hashTable, word) == NULL)
		printf("%s appears to be misspelled or not in dictionary.\n", word);
	else
		printf("%s is in the dictionary.\n", word);

    /* Don't remove this. It is used for grading*/
    if(strcmp(word,"quit")==0)
      quit=!quit;
  }
  free(word);
  free(dictionary);
  return 0;
}

void loadDictionary(FILE* file, struct hashMap* ht)
{
	while (1)
	{
		char* word = getWord(file);
		if (word == NULL)
			break;
		else
		{
			insertMap(ht, word, 0);
			free(word);
			continue;
		}
	}
}

char* getFileName()
{
	char* fileName = (char*)malloc(sizeof(char) * 1024);
#ifdef _WIN32
	printf("Please enter a path to a dictionary file [.\\dictionary.txt]: ");
#else
	printf("Please enter a path to a dictionary file [./dictionary.txt]: ");
#endif
	
	fgets(fileName, 1024, stdin);
	
	/* strip newline*/
	char* newline = strchr(fileName, '\n');
	if (newline != NULL)
		*newline = '\0';

	if (strcmp(fileName, "\0") == 0)
		strcpy(fileName, "dictionary.txt");

	return fileName;
}

void printValue(ValueType v) {
	printf("Value:%d", v);
}


char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   (character == 39)) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
