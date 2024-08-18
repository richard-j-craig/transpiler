#include <ctype.h>
#include <stdio.h>

#define MAX_TOKENS 100

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_EOF,
} TokenType;

typedef struct {
    TokenType type;
    int value;  // Only used for TOKEN_INT
} Token;

// The argument is a pointer to the remaining input string
// given strings are pointers to the first character, it is a pointer to a pointer.
// If the string was inputted directly, it could not be modified, the pointer to 
// a pointer is only needed because the input is passed through two functions.
Token get_next_token(char** input) {
    while (isspace(**input)) {
        // remove the the first character of the string
        // by incrementing address of the pointer to the first character
        (*input)++;
    }

    if (isdigit(**input)) {
        int value = 0;
        while (isdigit(**input)) {
            value = value * 10 + (**input - '0');
            (*input)++;
        }
        return (Token){TOKEN_INT, value};
    } else if (**input == '+') {
        (*input)++;
        return (Token){TOKEN_PLUS, 0};
    } else {
        return (Token){TOKEN_EOF, 0};
    }
}

void tokenize(char* input, Token* tokens, int* num_tokens) {
    *num_tokens = 0;
    Token token;
    do {
        token = get_next_token(&input);
        tokens[(*num_tokens)++] = token;
    } while (token.type != TOKEN_EOF && *num_tokens < MAX_TOKENS);
}
