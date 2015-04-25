#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	assert(lst != 0);

	lst->firstLink = malloc(sizeof(struct DLink));
	lst->lastLink = malloc(sizeof(struct DLink));
	lst->firstLink->next = lst->lastLink;
	lst->firstLink->prev = 0;
	lst->lastLink->prev = lst->firstLink;
	lst->lastLink->next = 0;

	lst->size = 0;

}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	assert(lst != 0);
	assert(l != 0);

	struct DLink *newLink = malloc(sizeof(struct DLink));
	
	newLink->value = v;

	newLink->next = l;
	newLink->prev = l->prev;

	l->prev->next = newLink;
	l->prev = newLink;

	lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
	assert(lst != 0);
	
	_addLinkBefore(lst, lst->firstLink->next, e);
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	assert(lst != 0);

	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	assert(lst != 0);

	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	assert(lst != 0);
	return(lst->lastLink->prev->value);
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	assert(lst != 0);

	l->prev->next = l->next;
	l->next->prev = l->prev;

	free(l);
	
	lst->size--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
	assert(lst != 0);
	assert(lst->size > 0);

	_removeLink(lst, lst->firstLink->next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	assert(lst != 0);
	assert(lst->size > 0);

	_removeLink(lst, lst->lastLink->prev);
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
	if (lst->size > 0)
		return 0;
	else
		return 1;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */

}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	addFrontList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	
	struct DLink *tmp = lst->firstLink->next;

	for (int i = 0; i < lst->size; i++)
	{
		if (tmp->value == e)
			return 1;

		else
			tmp = tmp->next;
	}

	return(0);
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	struct DLink *tmp = lst->firstLink->next;

	for (int i = 0; i < lst->size; i++)
	{
		if (tmp->value == e)
			_removeLink(lst, tmp);

		else
			tmp = tmp->next;
	}
}

void deleteLinkedList (struct linkedList *lst) {

	struct DLink *curLink = lst->firstLink;

	while(curLink != lst->lastLink)
	{
		curLink = curLink->next;
		free(curLink->prev);
	}

	free(lst->lastLink);

	free(lst);
}