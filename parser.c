#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"



typedef struct ASTNode {
    TokenType type;
    TokenData data;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* newASTNode(TokenType type, TokenData data) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* parse(Token* tokens) {
    ASTNode* left = newASTNode(tokens->type, tokens->data);
    tokens++;

    while (tokens->type != TOKEN_EOF) {
        ASTNode* right = newASTNode(tokens[1].type, tokens[1].data);
        TokenData _data;
        _data.intValue = 0;
        ASTNode* parent = newASTNode(tokens->type, _data);
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
