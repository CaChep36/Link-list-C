#include <stdio.h>
#include <stdlib.h>

struct Node
{
    unsigned int data;
    struct Node *next;
};

void Push_Node(struct Node **L_Ref, unsigned int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;

    if ((*L_Ref) == NULL)
    {
        temp->next = temp;
        (*L_Ref) = temp;
    }
    else
    {
        temp->next = (*L_Ref)->next;
        (*L_Ref)->next = temp;
        *L_Ref = temp;
    }
}

void Print_List_Reverse(struct Node *L_Ref)
{
    if (L_Ref == NULL)
    {
        return;
    }

    struct Node *cur = L_Ref->next;

    if (cur == L_Ref)
    {
        printf("%d ", cur->data);
        return;
    }

    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *head = cur;

    do
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while (cur != head);

    cur = prev;
    do
    {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != prev);

    // cur = prev;
    // prev = NULL;
    // do
    // {
    //     next = cur->next;
    //     cur->next = prev;
    //     prev = cur;
    //     cur = next;
    // } while (cur != head);
}

int main()
{
    struct Node *last = NULL;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        unsigned int a;
        scanf("%u", &a);
        Push_Node(&last, a);
    }

    Print_List_Reverse(last);

    return 0;
}