/*
============================================================================
 Name        : TEST_file_management.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Unit test for 'file_management.c'
============================================================================
*/

#ifndef TEST_TEST_FILE_MANAGEMENT_TEST_FILE_MANAGEMENT_H_
#define TEST_TEST_FILE_MANAGEMENT_TEST_FILE_MANAGEMENT_H_

#include "../../file_management/file_management.h"
#include "../../utility/utility.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
 * TEST 1
 */
void TEST_read_entire_file() {

	const char *test_data = "Andrea Graziani";

	// Allocate needed memory for a 'stat' struct...
	struct stat *file_stat = malloc(sizeof(struct stat));
	if (file_stat == NULL)
		exit_failure(concatenate_strings(2, "'TEST_read_entire_file' function: 'malloc' --> ", strerror(errno)));

	// Getting data from file (in this case plain text)...
    char *test_output = (char *) read_entire_file("/cygdrive/c/test/test.txt", file_stat);
    if (test_output == NULL)
    	exit_failure(concatenate_strings(2, "'TEST_read_entire_file' function: 'read_entire_file' --> ", strerror(errno)));

    assert(file_stat->st_size == 15);
    assert(memcmp(test_output, test_data, file_stat->st_size) == 0);

    free(test_output);
}

#endif /* TEST_TEST_FILE_MANAGEMENT_TEST_FILE_MANAGEMENT_H_ */
