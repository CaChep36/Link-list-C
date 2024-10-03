#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Add_Node_Head(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Insert_Node(struct Node **head_ref, int a, int b)
{
    struct Node *temp = *head_ref;

    while (temp != NULL)
    {
        if (temp->data == b)
        {
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = a;
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }

    Add_Node_Head(head_ref, a);
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
        int a, b;
        scanf("%d %d", &a, &b);
        Insert_Node(&head, a, b);
    }
    Print_List(head);

    return 0;
}
