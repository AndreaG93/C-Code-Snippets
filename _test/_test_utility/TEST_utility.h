/*
============================================================================
 Name        : TEST_utility.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Unit test for 'utility.c'
============================================================================
 */

#ifndef TEST__TEST_UTILITY_TEST_UTILITY_H_
#define TEST__TEST_UTILITY_TEST_UTILITY_H_

/*
 * TEST 1
 */
void TEST_concatenate_strings() {

	assert(strcmp("/test/test.txt", concatenate_strings(2, "/test/", "test.txt")) == 0);
}

/*
 * TEST 2
 */
void TEST_convert_to_string() {

	assert(strcmp(convert_to_string( (long double *) 35, "%d"), "35") == 0);
	assert(strcmp(convert_to_string( (long double *) 30000, "%ld"), "30000") == 0);
}

#endif /* TEST__TEST_UTILITY_TEST_UTILITY_H_ */
