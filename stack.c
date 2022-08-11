#include <stdio.h>
#include <stdbool.h>

int top = -1; 
const int stack_len = 10;
int stack[10];

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool isFull()
{
    if (top == stack_len - 1)
        return true;
    else
        return false;
}

void push(int value)
{
    if (top < stack_len - 1)
    {
        top++;
        stack[top] = value;
        printf("\n------%d pushed in the stack------\n", value);
    }
    else
        printf("\n------Stack is Full------\n");
}
void pop()
{

    if (isEmpty())
        printf("-----Stack is Empty------\n");
    else
        printf("------%d value Removed in stack------\n", stack[top--]);
}
void peek()
{
    if (isEmpty())
        printf("------Stack is Empty------\n");

    else
        printf("------Stack's peek value is %d------\n", stack[top]);
}

int main()
{
    bool sign = true;
    int condition,number;
    while (sign == true)
    {
        printf("\nYou can select following stack operations.\n");
        printf("\n1.push() \n2.pop() \n3.peek() \n4.isEmpty() \n5.isFull() \n6.Program End\n\n");
        printf("Enter your choose operation -->'1,2,3,4,5,6' : ");

        scanf("%d", &condition);
        printf("\n");
        switch (condition)
        {
        case 1:
            printf("Enter the integer value: ");
            scanf("%d", &number);
            push(number);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty() == 1)
                printf("------True------\n");
            else
                printf("------False------\n");
            break;
        case 5:
            if (isFull() == 1)
                printf("------True------\n");
            else
                printf("------False------\n");
            break;
        case 6:
            printf("------Program is End...Thank you!------\n\n");
            sign = false;
            break;
        default:
            printf("------Your operation is invalid,please try again.------\n");
            break;
        }
    }
    return 0;
}
