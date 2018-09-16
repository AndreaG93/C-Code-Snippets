/*
============================================================================
 Name        : file_management.h
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Utility function for file management.
============================================================================
*/

#ifndef FILE_MANAGEMENT_FILE_MANAGEMENT_H_
#define FILE_MANAGEMENT_FILE_MANAGEMENT_H_

#include <sys/stat.h>

void *read_entire_file(char *pathname, struct stat *file_stat);

#endif /* FILE_MANAGEMENT_FILE_MANAGEMENT_H_ */
