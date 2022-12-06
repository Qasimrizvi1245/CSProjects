#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *next;
}
        Node;

int length(Node* head)
{
    int count = 0;
    Node *curr = head;

    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int contains(Node *head, int n)
{
    Node *curr = head;

    while(curr != NULL)
    {
        if(curr->data == n)
            return 1;

        curr = curr->next;
    }
    return 0;
}

Node* insert(Node *head, int n)
{
    if(contains(head,n) == 1)
        return head;

    Node *node = (Node*)malloc(sizeof(Node));

    if(node != NULL)
    {
        node->data = n;
        node->next = NULL;

        if(head == NULL)
            head = node;

        else
        {
            Node *curr = head;
            Node *prev = NULL;

            while(curr != NULL)
            {
                if(curr->data > node->data)
                {
                    if(prev == NULL)
                    {
                        node->next = head;
                        head = node;
                    }
                    else
                    {
                        node->next = curr;
                        prev->next = node;
                    }
                    return head;
                }
                prev = curr;
                curr = curr->next;
            }
            prev->next = node;
        }
    }
    return head;
}

Node* delete(Node* head, int n)
{
    if(head != NULL)
    {
        if(head->data == n)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
        else
        {

            Node *curr = head;
            Node *prev = NULL;

            while(curr != NULL)
            {
                if(curr->data == n)
                {
                    prev->next = curr->next;
                    free(curr);
                    return head;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}

void print(Node *head)
{
    Node *curr = head;

    while(curr != NULL)
    {
        printf(" %d",curr->data);
        curr = curr->next;
    }
}

int main(void)
{
    Node *head = NULL;
    Node *curr;
    int data;
    char cmd;
    do
    {
        fflush(stdout);
        cmd = 'k';
        scanf(" %c %d",&cmd,&data);

        if((tolower(cmd) != 'i') && (tolower(cmd) != 'd'))
            break;
        if(tolower(cmd) == 'i')
            head = insert(head,data);
        else
            head = delete(head,data);

        printf("%d :",length(head));
        print(head);
        printf("\n");

    } while((tolower(cmd) == 'i') || (tolower(cmd) == 'd'));

    while(head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr);
    }

    return EXIT_SUCCESS;
}