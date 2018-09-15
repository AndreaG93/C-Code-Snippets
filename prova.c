/*
 ============================================================================
 Name        : prova.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <assert.h>

/**
 * This function is used to terminate application execution displaying a specified error message.
 *
 * @param str2 -> A pointer to an error message.
 */

/*
 * hhhhhhhhhhhhhhhhhnhgnhgnhgnghnhgnhgngh
 *
 */
void exit_failure(char *error_msg) {
    fprintf(stderr, "%s", error_msg);
    exit(EXIT_FAILURE);
}

/**
 * This function is used to concatenate a set of strings.
 * The amount of strings to concatenate is specified by 'n_args' argument.
 *
 * @param n_args -> The amount of strings to concatenate.
 * @param ... 	 -> Strings.
 * @return: A string.
 */
char *concatenate_strings(unsigned int n_args, ...) {

    size_t memory_size = 0;
    va_list ap;

    // Initialize 'va_list'
    va_start(ap, n_args);

    // Calc buffer size
    for (register unsigned int i = 1; i <= n_args; i++)
        memory_size += (strlen(va_arg(ap, char *)));

    // Allocate memory
    char *output = calloc(1, memory_size * sizeof(char));
    if (output == NULL)
        exit_failure(concatenate_strings(2, "'concatenate_strings' function: 'calloc' --> ", strerror(errno)));

    // Restart 'va_list'
    va_start(ap, n_args);

    for (register unsigned int i = 1; i <= n_args; i++)
        strcat(output, va_arg(ap, char *));

    // Free pointless memory...
    va_end(ap);

    return output;
}


/**
 * This function is used to test 'concatenate_strings' function.
 */
void TEST_concatenate_strings(){
    assert(strcmp("/test/test.txt", concatenate_strings(2, "/test/", "test.txt")) == 0);
}




int main(void) {
	TEST_concatenate_strings();
	return EXIT_SUCCESS;
}
