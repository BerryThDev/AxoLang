typedef enum {
    IF,
    LET,
    SEMI_COLON,
    ILLEGAL,
} Token;

char* token_name(Token token); 

Token token_from_name(char* token_name); 

