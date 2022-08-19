#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert_beginning();
void insert_end();
void insert_middle();

void delete_beginning();
void delete_end();

void print();

struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head = 0, *temp, *newnode;
int numbers = 0;
int count = 0;
struct node *node_create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    newnode->pre = 0;
    printf(" Enter the node value: ");
    scanf("%d", &newnode->data);
    count++;
    return newnode;
}
int main()
{
    int operate;
    bool condition = true;
    char x[60] = "**********************************************************";
    printf("\n--------------------Doubly linked list--------------------\n\n");
    while (condition)
    {
        printf(">>> Insert Elements to a linked List :\n");
        printf("\n\t\t1 ==> Insert at the beginning\n\t\t2 ==> Insert at the end \n\t\t3 ==> Insert at the middle\n\n");
        printf(">>> Delete from a linked List :\n");
        printf("\n\t\t4 ==> Delete from the beginning\n\t\t5 ==> Delete from the end\n\n");

        printf(">>> Other operations for a linked list :\n");
        printf("\t\t6 ==> Traverse a linked List\n");
        printf("\t\t7 ==> program End\n");
        printf("\n");

        printf(" Enter operations Number: ");
        scanf("%d", &operate);
        switch (operate)
        {
        case 1:
            printf("%s\n", x);
            insert_beginning();
            printf("%s\n\n", x);
            break;
        case 2:
            printf("%s\n", x);
            insert_end();
            printf("%s\n\n", x);
            break;
        case 3:
            printf("%s\n", x);
            insert_middle();
            printf("%s\n\n", x);
            break;
        case 4:
            printf("%s\n", x);
            delete_beginning();
            printf("%s\n\n", x);
            break;
        case 5:
            printf("%s\n", x);
            delete_end();
            printf("%s\n\n", x);
            break;
        case 6:
            printf("%s\n", x);
            print();
            printf("%s\n\n", x);
            break;
        case 7:
            condition = false;
            printf("%s\n", x);
            printf("\t\t.......PROGRAM IS END.......\n");
            printf("%s\n\n", x);
            break;
        default:
            printf("%s\n\n", x);
            break;
        }
    }
    return 0;
}
// a. Insert Elements to a nexted List
// i. Insert at the beginning
void insert_beginning()
{
    if (head != 0)
    {
        node_create();
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
    }
    else
        printf(" nexted list is Underflow\n");
}
// ii. Insert at the end
void insert_end()
{
    node_create();
    temp = head;
    struct node *prePTR;
    if (head == 0)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        while (temp != 0)
        {
            prePTR = temp;
            temp = temp->next;
        }
        prePTR->next = newnode;
        newnode->pre = prePTR;
    }
}
// iii. Insert at the middle
void insert_middle()
{
    // count is a length of a nexted list
    int i = 0 , position;
    struct node *prePTR;
    if (count % 2 == 0 && head != 0)
    {
        temp = head;
        // printf("count: %d\n", count);
        node_create();
        while (i < count / 2)
        {
            prePTR = temp;
            temp = temp->next;
            i++;
        }
        prePTR->next = newnode;
        newnode->pre = prePTR;
        newnode->next = temp;
        temp->pre = newnode;
    }
    else
        printf(" For now you created linked list hasn't a middle.\n\t\tINSERT NEW ELEMENT & AFTER TRY THAT... \n");
}
// b. Delete from a linked List
// i. Delete from the beginning
void delete_beginning()
{
    if (head != 0)
    {
        temp = head;
        head = temp->next;
        head->pre = 0;
        printf(" Delete from the beginning element: %d\n", temp->data);
        free(temp);
        temp = head;
    }
    else
        printf(" linked list is Underflow\n");
}
// ii. Delete from the end
void delete_end()
{
    temp = head;
    struct node *prePTR, *currentPTR;
    if (head != 0)
    {
        while (temp != 0)
        {
            if (head == temp)
            {
                currentPTR = temp;
                temp = temp->next;
            }
            else
            {
                prePTR = currentPTR;
                currentPTR = temp;
                temp = temp->next;
            }
        }
        if (head == currentPTR)
        
            head = 0;
        
        else
            prePTR->next = 0;

        printf(" Delete from the beginning element: %d\n", currentPTR->data);
        free(temp);
    }
    else
        printf(" linked list is Underflow\n");
}
// d. Traverse a linked List
void print()
{
    temp = head;
    if (head != 0)
    {
        printf(" linked list Elements: ");
        while (temp != 0)
        {
            printf(" %d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
        printf(" linked list is Underflow\n");
}
