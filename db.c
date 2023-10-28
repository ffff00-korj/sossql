#include "cli/tools.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    InputBuffer *input_buffer = new_input_buffer();

    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit")) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command %s.\n", input_buffer->buffer);
            exit(EXIT_FAILURE);
        }
    }
}
