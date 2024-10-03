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

void Delete_Node_After(struct Node **head_ref, int data)
{
    struct Node *temp = *head_ref;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    struct Node *node_x = temp->next;

    if (node_x->next == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = node_x->next;
    }

    free(node_x);
}

// void Delete_Node_End(struct Node **head_ref, int n)
// {
//     struct Node *temp, *prev;

//     for (int i = 0; i < n; i++)
//     {
//         if (*head_ref == NULL)
//         {
//             return;
//         }

//         if ((*head_ref)->next == NULL)
//         {
//             free(*head_ref);
//             *head_ref = NULL;
//             return;
//         }

//         temp = *head_ref;
//         while (temp->next != NULL)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = NULL;
//         free(temp);
//     }
// }
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
    struct Node *head = NULL;
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        Add_Node_Head(&head, a);
    }

    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        scanf("%d", &tmp);
        Delete_Node_After(&head, tmp);
    }

    Print_List(head);
    return 0;
}