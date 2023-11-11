#include "cli/tools.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    InputBuffer *input_buffer = new_input_buffer();

    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (is_metacommand(input_buffer->buffer)) {
            switch (do_metacommand(input_buffer)) {
            case METACOMMAND_SUCCESS:
                continue;
            case METACOMMAND_UNRECOGNIZED_COMMAND:
                printf("Unrecognized command %s.\n", input_buffer->buffer);
                continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
        case PREPARE_SUCCESS:
            break;
        case PREPARE_UNRECOGNIZED_STATEMENT:
            printf("Unrecognized keyword at start of '%s'.\n",
                   input_buffer->buffer);
            continue;
        }
        execute_statement(&statement);
        printf("Executed.\n");
    }
}
