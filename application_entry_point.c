/*
============================================================================
 Name        : application_entry_point.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Application entry point.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>

#include "_test/_test_file_management/TEST_file_management.h"
#include "_test/_test_utility/TEST_utility.h"

#define EXECUTE_UNIT_TEST

#ifdef EXECUTE_UNIT_TEST

/*
 * This function is used to execute all unit test.
 */
void execute_all_unit_test() {

	TEST_read_entire_file();
	TEST_concatenate_strings();
	TEST_convert_to_string();
}

#endif

/*
 * Application 'main' function.
 */
int main(void) {

#ifdef EXECUTE_UNIT_TEST
	execute_all_unit_test();
#endif

	return EXIT_SUCCESS;
}
