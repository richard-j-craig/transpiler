#ifndef LEXER_H
#define LEXER_H

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

void tokenize(char* input, Token* tokens, int* num_tokens);

#endif // LEXER_H
