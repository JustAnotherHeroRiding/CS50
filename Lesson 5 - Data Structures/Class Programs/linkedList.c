#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Free memory used until now
            return 1;
        }
        n->number = number;
        n->next = list;

        list = n;
        // printf("%d\n", number);
        // printf("%s\n", argv[i]);
    }

    // Print whole list
    node *ptr = list;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    
    return 0;
}