#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"


typedef struct ASTNode {
    TokenType type;
    TokenData data;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* parse(Token* tokens);