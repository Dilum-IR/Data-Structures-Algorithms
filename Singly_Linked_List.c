#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void insert_beginning();
void insert_end();
void insert_middle();
void delete_beginning();
void delete_end();
void search();
void print();
void reverse();
void length();
struct node
{
    int data;
    struct node *link;
};
struct node *head = 0, *temp, *newnode;
int numbers = 0;
int count = 0;
struct node *node_create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = 0;
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
    printf("\n--------------------singly linked list--------------------\n\n");
    while (condition)
    {
        printf(">>> Insert Elements to a Linked List :\n");
printf("\n\t\t1 ==> Insert at the beginning\n\t\t2 ==> Insert at the end \n\t\t3 ==> Insert at the middle\n\n");
printf(">>> Delete from a Linked List :\n");
printf("\n\t\t4 ==> Delete from the beginning\n\t\t5 ==> Delete from the end\n\n");
printf(">>> Other operations for a linked list :\n");
printf("\n\t\t6 ==> Search an Element on a Linked List\n");
printf("\t\t7 ==> Traverse a Linked List\n");
printf("\t\t8 ==> Reverse a linked list\n");
printf("\t\t9 ==> Length of a Linked List\n");
printf("\t\t10 ==> program End\n");
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
            search();
            printf("%s\n\n", x);
            break;
        case 7:
            printf("%s\n", x);
            print();
            printf("%s\n\n", x);
            break;
        case 8:
            printf("%s\n", x);
            reverse();
            printf("%s\n\n", x);
            break;
        case 9:
            printf("%s\n", x);
            length();
            printf("%s\n\n", x);
            break;
        case 10:
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
// a. Insert Elements to a Linked List
// i. Insert at the beginning
void insert_beginning()
{
    if (head != 0)
    {
        node_create();
        newnode->link = head;
        head = newnode;
    }
    else
        printf(" Linked list is Underflow\n");
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
            temp = temp->link;
        }
        prePTR->link = newnode;
    }
}
// iii. Insert at the middle
void insert_middle()
{
    // count is a length of a linked list
    int i = 0;
    struct node *prePTR;
    if (count % 2 == 0 && head != 0)
    {
        temp = head;
        // printf("count: %d\n", count);
        node_create();
        while (i < count / 2)
        {
            prePTR = temp;
            temp = temp->link;
            i++;
        }
        prePTR->link = newnode;
        newnode->link = temp;
    }
    else
printf(" For now you created linked list hasn't a middle.\n\t\tINSERT NEW ELEMENT & AFTER TRY THAT... \n");
}
// b. Delete from a Linked List
// i. Delete from the beginning
void delete_beginning()
{
    if (head != 0)
    {
        temp = head;
        head = temp->link;
        printf(" Delete from the beginning element: %d\n", temp->data);
        free(temp);
        temp = head;
    }
    else
        printf(" Linked list is Underflow\n");
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
                temp = temp->link;
            }
            else
            {
                prePTR = currentPTR;
                currentPTR = temp;
                temp = temp->link;
            }
        }
        prePTR->link = 0;
        printf(" Delete from the beginning element: %d\n", currentPTR->data);
        free(temp);
    }
    else
        printf(" Linked list is Underflow\n");
}
// c. Search an Element on a Linked List
void search()
{
    temp = head;
    int value;
    if (head != 0)
    {
        printf(" Enter to search an Element value: ");
        scanf("%d", &value);
        while (temp->data != value)
        {
            if (temp->link != 0)
                temp = temp->link;
            // if temp address "0" then loop is break
            else
                break;
        }
        if (temp->data == value)
            printf(" Your Search an Element on a Linked List\n");
        else
            printf(" Your search element isn't on a linked list\n");
    }
    else
        printf(" Linked list is Underflow\n");
}
// d. Traverse a Linked List
void print()
{
    temp = head;
    if (head != 0)
    {
        printf(" linked list Elements: ");
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else
        printf(" Linked list is Underflow\n");
}
// reverse a linked list.
void reverse()
{
    int i = 1;
    struct node *prePTR, *currentPTR;
    temp = head;
    if (head != 0)
    {
        while (temp != 0)
        {
            // linked list first element situation
            if (temp == head)
            {
                currentPTR = temp;
                temp = temp->link;
                currentPTR->link = 0;
            }
            // linked list other element situations
            else
            {
                prePTR = currentPTR;
                currentPTR = temp;
                temp = temp->link;
                currentPTR->link = prePTR;
            }
            // head linked the end element
            if (temp == 0)
            {
                head = currentPTR;
            }
        }
printf("A Linked list reversed.Now You can see it , if use the traverse operation\n");
    }
    else
        printf(" Linked list is Underflow\n");
}
// Length of a Linked List
void length()
{
    int len = 0;
    temp = head;
    if (head != 0)
    {
        while (temp != 0)
        {
            len++;
            temp = temp->link;
        }
        printf(" Length of a Linked List : %d\n", len);
    }
    else
        printf(" Linked list is Underflow\n");
}