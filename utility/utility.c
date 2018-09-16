/*
============================================================================
 Name        : utility.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Utility function for general use.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

/*
 * This function is used to terminate current application returning an 'EXIT_FAILURE'
 * displaying a specified error message.
 *
 * @param *error_msg -> An error message.
 */
void exit_failure(char *error_msg) {

    fprintf(stderr, "%s", error_msg);
    exit(EXIT_FAILURE);

}

/*
 * This function is used to concatenate a set of strings.
 * The amount of strings to concatenate is specified by 'n_args' argument.
 *
 * If successful, a pointer to a concatenated string is returned; otherwise 'NULL' is returned, and 'errno' is set appropriately.
 *
 * @param n_args -> The amount of strings to concatenate.
 * @param ... 	 -> Strings.
 * @return: A string.
 */
char *concatenate_strings(unsigned int n_args, ...) {

	size_t memory_size = 0;
	va_list ap;

	// Phase 1 --> Initialize 'va_list' variable...
	// ============================================================================ //
	va_start(ap, n_args);

	// Phase 2 --> Count needed memory for output...
	// ============================================================================ //
	for (register unsigned int i = 1; i <= n_args; i++)
		memory_size += (strlen(va_arg(ap, char *)));

	// Phase 3 --> Allocate needed memory for output.
	// 			   If successful start 'va_list' variable and start concatenation...
	// ============================================================================ //
	char *output = calloc(1, memory_size * sizeof(char));
	if (errno == 0) {

		va_start(ap, n_args);

		for (register unsigned int i = 1; i <= n_args; i++)
			strcat(output, va_arg(ap, char *));
	}

	// Phase 4 --> Free memory...
	// ============================================================================ //
	va_end(ap);

	return output;
}

/**
 * This function is used to convert a numeric value into a 'string'.
 *
 * If successful, a pointer to aforementioned string is returned; otherwise 'NULL' is returned, and 'errno' is set appropriately.
 *
 * @param *data 	-> Value data to convert.
 * @param *template -> Template of specified data.
 * @return A string.
 */
char *convert_to_string(long double *data, char *template) {

	// Count char...
	int n = snprintf(NULL, 0, template, data);

	// Allocate needed memory for output...
	char *output = calloc(n + 1, sizeof(char));
	if (errno == 0) {

		// Build string and exit...
		snprintf(output, n + 1, template, data);

	}

	return output;
}
