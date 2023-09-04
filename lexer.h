#include <stdio.h>
#include "token.h"

Token* analyze(FILE *file, int* token_size);

Token read_until_next_token(FILE* file, int *status);

int is_whitespace(const char* current_char); 
