#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Add_At_Head(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void Print_List(struct Node *node)
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
    int n;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        Add_At_Head(&head, a);
    }

    Print_List(head);

    return 0;
}
