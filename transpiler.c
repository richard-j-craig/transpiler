#include <stdio.h>
#include "lexer.h"
#include "parser.h"

void printAST(ASTNode* node) {
    if (node == NULL) return;

    if (node->type == TOKEN_INT) {
        printf("%d ", node->value);
    } else if (node->type == TOKEN_PLUS) {
        printf("+ ");
    }

    printAST(node->left);
    printAST(node->right);
}

// Function to evaluate expressions
int eval(char* expr) {
    Token tokens[MAX_TOKENS];
    int num_tokens;
    // run lexer
    tokenize(expr, tokens, &num_tokens);
    // print tokens
    for (int i = 0; i < num_tokens; i++) {
        switch (tokens[i].type) {
            case TOKEN_INT:
                printf("Got an integer: %d\n", tokens[i].value);
                break;
            case TOKEN_PLUS:
                printf("Got a plus sign\n");
                break;
            case TOKEN_EOF:
                printf("End of input\n");
                break;
        }
    }

    // run parser
    ASTNode* root = parse(tokens);
    // print AST
    printAST(root);

    return 0;
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, 100, stdin);
    int result = eval(expr);
    printf("Result: %d\n", result);
    return 0;
}
