/*
============================================================================
 Name        : file_management.c
 Author      : Andrea Graziani
 Version     : 1.0
 Description : Utility function for file management.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/*
 * This function is used to read an entire file from disk loading data into a newly allocated buffer.
 *
 * If successful, a pointer to aforementioned buffer is returned and all file information
 * stored into given 'stat' struct; otherwise 'NULL' is returned, and 'errno' is set appropriately.
 *
 * @param pathname  -> A path to a existent readable and file.
 * @param file_stat -> A pointer to a 'stat' struct.
 * @return - A buffer containing read data.
 */
void *read_entire_file(char *pathname, struct stat *file_stat) {

	int file_descriptor;
	void *output;
	errno = 0;

	// Phase 1 --> Test the existence and readability of specified file...
	// ============================================================================ //
	if (access(pathname, R_OK) != 0)
		return NULL;

	// Phase 2 --> Open file and read needed file information
	//			   to allocate enough memory to load specified file on a buffer...
	// ============================================================================ //
	file_descriptor = open(pathname, O_RDONLY);
	if (errno != 0)
		return NULL;

	fstat(file_descriptor, file_stat);
	if (errno != 0)
		return NULL;

	output = calloc(file_stat->st_size, sizeof(char));
	if (errno != 0)
		return NULL;

	// Phase 3 --> Reading.
	// ============================================================================ //
	for (;;) {
		size_t read_byte = read(file_descriptor, output, file_stat->st_size);

		// Phase 3.1 --> Read successfully...
		// ---------------------------------------------------------------------------- //
		if (read_byte == 0 || read_byte == file_stat->st_size)
			break;

		// Phase 3.2 --> Error during reading. Free used memory, preparing for 'NULL'
		// returning...
		// ---------------------------------------------------------------------------- //
		else if (read_byte == -1) {

			free(output);
			output = NULL;
			break;
		}
	}

	// Phase 4 --> Close file.
	// ============================================================================ //
	close(file_descriptor);
	if (errno != 0) {

		free(output);
		output = NULL;
	}

	return output;
}
