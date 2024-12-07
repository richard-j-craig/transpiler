#include <stdio.h>
#include "lexer.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10


void print2DUtil(ASTNode* root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    // Print right subtree
    print2DUtil(root->right, space);

    // Print current node
    printf("\n");
    for (int i = COUNT; i < space; i++)
        if (i % COUNT == 0)
        {
            printf("|");
        }
        else if (i  >= space - COUNT)
        {
            printf("-");
        }
        else
        {
            printf(" ");
        }
    if (root->type == TOKEN_INT)
    {
        printf("%d", root->data);
    }
    else if (root->type == TOKEN_PLUS)
    {
        printf("+");
    }

    // Print left subtree
    print2DUtil(root->left, space);
}

void print2D(ASTNode* root) {
    print2DUtil(root, 0);
}


// Function to evaluate expressions
int eval(char *expr)
{
    Token tokens[MAX_TOKENS];
    int num_tokens;
    // run lexer
    tokenize(expr, tokens, &num_tokens);
    // print tokens
    for (int i = 0; i < num_tokens; i++)
    {
        switch (tokens[i].type)
        {
        case TOKEN_INT:
            printf("Got an integer: %d\n", tokens[i].data);
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
    print2D(root);

    return 0;
}

int main()
{
    char expr[100] = "1 + 20 + 4 + 3";
    // char expr[100];
    // printf("Enter an expression: ");
    // fgets(expr, 100, stdin);
    int result = eval(expr);
    // printf("Result: %d\n", result);
    return 0;
}
