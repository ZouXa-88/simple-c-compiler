#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

typedef struct TreeNode
{
    char *name;
    char *value;
    int numChildren;
    struct TreeNode **children;
} TreeNode;

#define MAX_NODES 1024
TreeNode *allocatedNodes[MAX_NODES];
int numAllocated = 0;

TreeNode *createNode(const char *name, char *value, int numChildren)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->name = my_strdup(name);
    node->value = value ? value : NULL;
    node->numChildren = numChildren;
    if (numChildren > 0)
        node->children = (TreeNode **)malloc(numChildren * sizeof(TreeNode *));
    else
        node->children = NULL;

    if (numAllocated < MAX_NODES)
        allocatedNodes[numAllocated++] = node;
    else
    {
        fprintf(stderr, "Error: Too many allocated nodes\n");
        freeAllNodes();
        exit(EXIT_FAILURE);
    }

    return node;
}

void freeNode(TreeNode *node)
{
    if (node == NULL)
        return;
    if (node->children)
        free(node->children);
    free(node);
}

void freeAllNodes()
{
    for (int i = 0; i < numAllocated; i++)
    {
        freeNode(allocatedNodes[i]);
    }
    numAllocated = 0;
}

void writeJson(TreeNode *node, FILE *file)
{
    if (node == NULL)
        return;

    static char spaces[100] = "";

    fprintf(file, "%s{\n", spaces);
    fprintf(file, "%s  \"name\": \"%s\"", spaces, node->name);
    if (node->value)
    {
        if (node->value[0] == '"')
            fprintf(file, ",\n%s  \"value\": %s", spaces, node->value);
        else
            fprintf(file, ",\n%s  \"value\": \"%s\"", spaces, node->value);
    }
    if (node->children)
    {
        fprintf(file, ",\n%s  \"children\": [\n", spaces);
        strcat(spaces, "    ");
        for (int i = 0; i < node->numChildren; i++)
        {
            writeJson(node->children[i], file);
            if (i < node->numChildren - 1)
            {
                fprintf(file, ",\n", spaces);
            }
            else
            {
                fprintf(file, "\n", spaces);
            }
        }
        spaces[strlen(spaces) - 4] = '\0';
        fprintf(file, "%s  ]", spaces);
    }
    fprintf(file, "\n%s}", spaces);
}
