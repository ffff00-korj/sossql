#include "tools.h"
#include <stdbool.h>

void exit_from_program(InputBuffer *input_buffer) {
    close_input_buffer(input_buffer);
    exit(EXIT_SUCCESS);
}
