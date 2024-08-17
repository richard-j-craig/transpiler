#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"



typedef struct ASTNode {
    TokenType type;
    int value;  // Only used for TOKEN_INT
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* newASTNode(TokenType type, int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* parse(Token* tokens) {
    ASTNode* left = newASTNode(tokens->type, tokens->value);
    tokens++;

    while (tokens->type != TOKEN_EOF) {
        ASTNode* right = newASTNode(tokens[1].type, tokens[1].value);
        ASTNode* parent = newASTNode(tokens->type, 0);
        parent->left = left;
        parent->right = right;
        left = parent;
        tokens += 2;
    }

    return left;
}

// int main() {
//     Token tokens[] = {
//         {TOKEN_INT, 1},
//         {TOKEN_PLUS, 0},
//         {TOKEN_INT, 2},
//         {TOKEN_PLUS, 0},
//         {TOKEN_INT, 3},
//         {TOKEN_EOF, 0}
//     };

//     ASTNode* root = parse(tokens);
//     printAST(root);
//     return 0;
// }
