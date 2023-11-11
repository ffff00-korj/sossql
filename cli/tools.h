#ifndef CLITOOLS_H
#define CLITOOLS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    METACOMMAND_SUCCESS,
    METACOMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
    StatementType type;
} Statement;

InputBuffer *new_input_buffer();

void print_prompt();

void read_input(InputBuffer *input_buffer);

void close_input_buffer(InputBuffer *input_buffer);

bool is_metacommand(char *command);

MetaCommandResult do_metacommand(InputBuffer *input_buffer);

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement);

void execute_statement(Statement *statement);

#endif
