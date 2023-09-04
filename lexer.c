#include "lexer.h"
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DONE 1
#define TOKEN_LIST_STARTING_SIZE 50

Token* analyze(FILE* file, int* token_size) {
    Token* tokens = malloc(sizeof(Token) * TOKEN_LIST_STARTING_SIZE);
    int current_token_size = TOKEN_LIST_STARTING_SIZE;
    int status = 0;

    while (status != DONE) {
        tokens[*token_size] = read_until_next_token(file, &status);
        (*token_size)++;

        if(*token_size > current_token_size - 1) {
           int new_size = current_token_size * 2;
           Token* possible_ptr = realloc(tokens, new_size * sizeof(Token));

           if(possible_ptr != NULL) {
               current_token_size = new_size;
               tokens = possible_ptr;
           } else {
               printf("Error: Unable to finish lexing. Failed to allocate enough memory.");
               break;
           }
        }
    }

    return tokens;
}

Token read_until_next_token(FILE* file, int* status) {
    char current_buffer[3] = {0};
    int current_buffer_counter = 0; 
    char current;

    while((current = fgetc(file)) != EOF) {
        current_buffer[current_buffer_counter] = current;

        if(isspace(current)) {
            continue;
        }

        Token token = token_from_name(current_buffer);
        
        if(token != ILLEGAL) {
            return token; 
        }

        current_buffer_counter++;

        if(current_buffer_counter > 2) {
            return ILLEGAL;
        }
    }

    if(current == EOF) {
        *status = DONE;
        return ILLEGAL;
    } else {
       return ILLEGAL; 
    }
}

char* token_name(Token token) {
    switch (token) {
        case IF: {
            return "if";
            break;
        }
        case LET: {
            return "let";
            break;
        }
        case SEMI_COLON: {
            return ";";
            break;
        }
        case ILLEGAL: {
            return "";
            break;
        }
    }

    return "";
}

Token token_from_name(char* token_name) {
   if(strcmp(token_name, "if") == 0) {
       return IF;
   }

   if(strcmp(token_name, "let") == 0) {
       return LET;
   }


   if(strcmp(token_name, ";") == 0) {
       return SEMI_COLON;
   }

   return ILLEGAL;
}

