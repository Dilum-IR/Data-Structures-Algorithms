#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {

        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
    {
        struct node *cur;
        if (data <= root->data)
        {
            cur = insert(root->left, data);
            root->left = cur;
        }
        else
        {
            cur = insert(root->right, data);
            root->right = cur;
        }

        return root;
    }
}
int getHeight(struct node* root)
{
    if (root != NULL)
    {
        int leftSide = getHeight(root->left);
        int rightSide = getHeight(root->right);
        
        if (leftSide>rightSide)
        {
            return leftSide+1;
        }
        else
            return rightSide+1;
    }
    else
        return 0;
}
int main(int argc, char const *argv[])
{

    int array[500];
    int x = 0, num;

    printf("Enter the Number of Nodes: ");
    scanf("%d", &num);
    printf("Enter the Node value one by one:\n");
    while (x < num)
    {
        if (num >= 1 && num <= 500)
        {
            printf("%d: ", x + 1);
            scanf("%d", &array[x]);
        }

        x++;
    }

    struct node *root = NULL;
    root=insert(root, array[0]);
    
    for (int i = 1; i < num; i++)
    {
        insert(root, array[i]);
    }

    printf(" binary tree's height= %d",getHeight(root)-1);
    return 0;
}
