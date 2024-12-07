#ifndef LEXER_H
#define LEXER_H

#define MAX_TOKENS 100

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_CHAR,
    TOKEN_ASSIGN,
    TOKEN_EOF,
} TokenType;

typedef union {
    int intValue;  // Used for literals or other integer values
    char* identifier;  // Used for variable names
    // Add other data types as needed
} TokenData;

typedef struct {
    TokenType type;
    TokenData data;  // Only used for TOKEN_INT and TOKEN_CHAR
} Token;

void tokenize(char* input, Token* tokens, int* num_tokens);

#endif // LEXER_H
