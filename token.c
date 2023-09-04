#include "token.h"
#include <string.h>

// What we use to convert a string into our tokens
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

// Mostly used to debug lexing using print statements
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
            return "ILLEGAL";
            break;
        }
    }

    return "ILLEGAL";
}

