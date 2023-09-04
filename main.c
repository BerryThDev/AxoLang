#include <stdio.h>
#include "lexer.h"

int main(int argc, const char* argv[]) {
    if(argc != 3) {
        printf("Expected a file to input and output.");
        return 0;
    }
    
    FILE *file = fopen(argv[1], "r");

    int tokens = 0;
    int i;
    
    Token* foundTokens = analyze(file, &tokens);

    for(i = 0; i < tokens; i++) {
        printf("%s", token_name(foundTokens[i]));
    }

    fclose(file);
 
}

