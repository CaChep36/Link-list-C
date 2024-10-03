#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteFirstN(struct Node **head_ref, int m)
{
    struct Node *temp;
    while (m > 0 && *head_ref != NULL)
    {
        temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        m--;
    }
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
        if (node != NULL)
        {
            printf(" ");
        }
    }
}

int main()
{
    int n, m;
    struct Node *head = NULL;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        push(&head, a);
    }

    deleteFirstN(&head, m);

    printList(head);

    return 0;
}
