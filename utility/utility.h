/*
============================================================================
 Name        : utility.h
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Utility function for general use.
============================================================================
*/

#ifndef UTILITY_UTILITY_H_
#define UTILITY_UTILITY_H_

void exit_failure(char *error_msg);
char *concatenate_strings(unsigned int n_args, ...);
char *convert_to_string(long double *data, char *template);

#endif /* UTILITY_UTILITY_H_ */
