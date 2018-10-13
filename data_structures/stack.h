/*
 ============================================================================
 Name        : Stack.h
 Author      : Andrea Graziani
 Version     : 1.0
 Description : ANSI C implemetation of a stack. (HEADER)
 ============================================================================
 */

#pragma once
#include <errno.h>
#include <stdlib.h>

// Represents a "Stack" structure
typedef struct Stack {

	unsigned int length;
	void* head;

} Stack;

/**
This function is used to allocate a new "Stack" structure.
If successful, a pointer to aforementioned "Stack" is returned; otherwise "NULL" is returned, and "errno" is set appropriately.

@return -> A pointer to a "Stack" structure.
*/
Stack* get_stack();

/**
This function is used to retrieve stack's length.
If stack is empty, "1" (true) is returned otherwise "0" (false); In case of failure, "-1" is returned, and "errno" is set appropriately.

@param stack -> A pointer to a "Stack" structure.
@return -> A char.
*/
char is_empty(Stack*);

/**
This function is used to retrieve stack's length.
If successful, stack's length is returned; otherwise "-1" is returned, and "errno" is set appropriately.

@param stack -> A pointer to a "Stack" structure.
@return -> An unsigned int.
*/
unsigned int get_length(Stack*);

/**
This function is used to insert data into specified "Stack" structure. 
In case of failure, 'errno' is set appropriately.

@param stack -> A pointer to a "Stack" structure.
@param data  -> A pointer to raw data.
*/
void push(Stack*, void*);

/**
This function is used to retrieve data from stack.
If successful, a pointer to aforementioned data from stack is returned; if stack is empty "NULL" is returned.
In case of failure "NULL" is returned, and "errno" is set appropriately.

@param stack -> A pointer to a "Stack" structure.
@return - A pointer to raw data.
*/
void* pop(Stack*);