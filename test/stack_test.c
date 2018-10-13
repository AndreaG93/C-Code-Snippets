/*
 ============================================================================
 Name        : stack_test.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Unit-Test for ANSI C implemetation of a stack.
 ============================================================================
 */

#include "../test/stack_test.h"

int test() {

	char *string1 = "Andrea";
	char *string2 = "Atsuko";
	char *string3 = "Chika";
	char *string4 = "Kumiko";

	Stack* stack = get_stack();
	push(stack, string1);
	push(stack, string2);
	push(stack, string3);
	push(stack, string4);

	// Checking stack metadata...
	// ============================================================================ //
	assert(get_length(stack) == 4);
	assert(is_empty(stack) == 0);

	// Check error detection...
	// ============================================================================ //
	assert(get_length(NULL) == -1);
	assert(errno == EINVAL);

	assert(is_empty(NULL) == -1);
	assert(errno == EINVAL);

	assert(pop(NULL) == NULL);
	assert(errno == EINVAL);

	errno = 0;
	push(NULL, NULL);
	assert(errno == EINVAL);

	errno = 0;
	push(stack, NULL);
	assert(errno == EINVAL);
	
	errno = 0;
	push(NULL, "test");
	assert(errno == EINVAL);

	// Cheching stored data...
	// ============================================================================ //
	assert(pop(stack) == string4);
	assert(pop(stack) == string3);
	assert(pop(stack) == string2);
	assert(pop(stack) == string1);

	return EXIT_SUCCESS;
}





