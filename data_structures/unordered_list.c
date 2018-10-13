/*
 ============================================================================
 Name        : UnorderedList.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : ANSI C implemetation of an anordered list.
 ============================================================================
 */

#include "UnorderedList.h"

/**
This function is used to construct a new 'UnorderedListNode' structure.

If successful, a pointer to aforementioned 'UnorderedListNode' is returned;
otherwise 'NULL' is returned, and 'errno' is set appropriately.

@return -> A pointer to a 'UnorderedListNode' structure.
*/
UnorderedListNode* __create_new_unordered_list_node(UnorderedList* data) {

	// Checking argument...
	if (data == NULL) {
		errno = EINVAL;
		return NULL;
	}

	// Allocate a new 'ListNode'.
	UnorderedListNode* new_stack_node = malloc(sizeof(UnorderedListNode));

	// If the allocation is successful, populate the data...
	if (new_stack_node != NULL) {
		new_stack_node->data = data;
		new_stack_node->next = NULL;
	}

	return new_stack_node;
}

/**
This function is used to construct a new 'UnorderedList' structure.

If successful, a pointer to aforementioned 'UnorderedList' is returned;
otherwise 'NULL' is returned, and 'errno' is set appropriately.

@return -> A pointer to a 'UnorderedList' structure.
*/
UnorderedList* get_unordered_list() {

	UnorderedList *list = malloc(sizeof(UnorderedList));

	if (list != NULL) {
		list->head = NULL;
		list->length = 0;
	}

	return list;
}

/**
This function is used to perform a specified function on every object stored into list.

@param list -> A pointer to an 'UnorderedList' structure.
@param function  -> A pointer to a function.
*/
void perform_action(UnorderedList* list, void(*function)(void *))
{
	UnorderedListNode *current = list->head;
	
	for (UnorderedListNode *current = list->head; current != NULL; current = current->next) {
		function(current->data);
	}
}

/**
This function is used to insert data into specified 'UnorderedList' structure..

In case of failure, 'errno' is set appropriately.

@param list -> A pointer to a 'UnorderedList' structure.
@param data  -> A pointer to raw data.
*/
void insert(UnorderedList *list, void *data) {

	UnorderedListNode *new_node = __create_new_unordered_list_node(data);

	if (list->length == 0) {
		list->head = new_node;
		list->tail = new_node;
	}
	else {
		list->tail->next = new_node;
		list->tail = new_node;
	}

	list->length++;
}

/**
*/
void *get(UnorderedList *list, unsigned int index) {

	int i = 0;

	for (UnorderedListNode *current_node = list->head; current_node != NULL; current_node = current_node->next)
	{
		if (i == index)
			return current_node->data;
		else
			i++;
	}

	return NULL;
}

/*
void delete(UnorderedList *p_list, unsigned int p_index) {

	UnorderedListNode *current = p_list->head;
	UnorderedListNode *previous = NULL;

	for (unsigned int i = 0; current != NULL; i++) {

		if (p_index == i) {

			if (p_list->length == 1)
			{
				p_list->head = NULL;
				p_list->tail = NULL;
			}
			else if (current == p_list->head) {
				p_list->head = current->next;
			}
			else {
				previous->next = current->next;
			}

			free(current);
			p_list->length--;
		}

		previous->next = current->next;
		current = current->next;
	}
}
*/