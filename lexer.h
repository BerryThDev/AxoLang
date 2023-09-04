#include <stdio.h>

typedef enum {
    IF,
    LET,
    SEMI_COLON,
    ILLEGAL,
} Token;


char* token_name(Token token); 

Token token_from_name(char* token_name); 

Token* analyze(FILE *file, int* token_size);

Token read_until_next_token(FILE* file, int *status);

int is_whitespace(const char* current_char); 
