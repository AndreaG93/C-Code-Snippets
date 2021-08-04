//
// Created by andrea on 04/08/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define READ_ALL -1
#define TRUE 1

void exit_failure(char *function_name) {

    fprintf(stderr, "'%s': %s", function_name, strerror(errno));
    exit(EXIT_FAILURE);
}

void double_buffer_size(void **buffer, size_t *buffer_size) {

    errno = 0;
    void *output = calloc(*buffer_size * 2, sizeof(char));
    if (output == NULL) {

        fprintf(stderr, "[ERROR] 'calloc': %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memcpy(output, *buffer, *buffer_size);
    free(*buffer);

    *buffer = output;
    *buffer_size = *buffer_size * 2;
}

void clear_input_buffer() {

    char character;

    while (TRUE) {

        errno = 0;
        size_t bytes_read = read(STDIN_FILENO, &character, sizeof(char));

        if (bytes_read == -1)
            exit_failure("read");
        else if (character == '\n' || character == EOF || character == '\0')
            return;
    }
}


char *read_string_from_standard_input(const size_t max_string_length) {

    int index = 0;
    char current_character;
    size_t current_buffer_size = 5;

    char *output = calloc(current_buffer_size, sizeof(char));
    if (output == NULL)
        exit_failure("calloc");

    while (TRUE) {

        errno = 0;
        size_t bytes_read = read(STDIN_FILENO, &current_character, sizeof(char));

        if (bytes_read == -1)
            exit_failure("read");
        else if (current_character == '\n' || current_character == EOF || current_character == '\0') {

            output[index] = '\0';
            break;

        } else {

            output[index] = current_character;
            index++;
        }

        if (index == max_string_length) {

            clear_input_buffer();
            break;
        }

        if (index == current_buffer_size)
            double_buffer_size((void **) &output, &current_buffer_size);

    }

    return output;
}


int main() {

    char *input1 = read_string_from_standard_input(READ_ALL);
    printf("Read all: %s\n", input1);

    char *input2 = read_string_from_standard_input(4);
    printf("4 character: %s\n", input2);

    free(input1);
    free(input2);
    exit(EXIT_SUCCESS);
}