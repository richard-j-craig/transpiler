#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"


typedef struct ASTNode {
    TokenType type;
    int value;  // Only used for TOKEN_INT
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* parse(Token* tokens);