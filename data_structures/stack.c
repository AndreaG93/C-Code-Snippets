/*
 ============================================================================
 Name        : Stack.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : ANSI C implemetation of a stack.
 ============================================================================
 */

#include "../data_structures/stack.h"

// Represents a node of a stack
typedef struct stack_node {
	
	void* data;
	struct stack_node* next;

} StackNode;

/**
This function is used to construct a new 'StackNode' structure.

If successful, a pointer to aforementioned 'StackNode' is returned;
otherwise 'NULL' is returned, and 'errno' is set appropriately.

@return -> A pointer to a 'Stack' structure.
*/
StackNode *__create_new_stack_node(void* data) {

	// Allocate a new 'ListNode'.
	StackNode* new_stack_node = malloc(sizeof(StackNode));

	// If the allocation is successful, populate the data...
	if (new_stack_node != NULL) {
		new_stack_node->data = data;
		new_stack_node->next = NULL;
	}

	return new_stack_node;
}

Stack *get_stack() {

	Stack *stack = malloc(sizeof(Stack));

	if (stack != NULL) {
		stack->head = NULL;
		stack->length = 0;
	}

	return stack;
}

unsigned int get_length(Stack* stack) {

	// Checking argument...
	if (stack == NULL) {
		errno = EINVAL;
		return -1;
	}

	return stack->length;
}

char is_empty(Stack* stack) {

	// Checking argument...
	if (stack == NULL) {
		errno = EINVAL;
		return -1;
	}

	return stack->length == 0;
}

void push(Stack* stack, void* data) {

	// Control of parameters...
	if (stack == NULL || data == NULL) {
		errno = EINVAL;
		return;
	}

	// Creation new node...
	errno = 0;
	StackNode* new_stack_node = __create_new_stack_node(data);
	if (errno != 0)
		return;

	// Pushing...
	new_stack_node->next = stack->head;
	stack->head = new_stack_node;

	stack->length++;
}

void* pop(Stack* stack) {

	// Control of parameters...
	if (stack == NULL) {
		errno = EINVAL;
		return NULL;
	}

	// CASE 0: Stack empty...
	if (stack->length == 0)
		return NULL;
	
	// CASE 1: Stack not empty...
	else {

		// Retrieve head node and data to return...
		StackNode* output_node = stack->head;
		void* output_data = output_node->data;

		// Update 'Stack' data...
		stack->head = output_node->next;
		stack->length--;

		// Free memory and return...
		free(output_node);

		return output_data;
	}
}
