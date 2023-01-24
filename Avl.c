#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

// structure of the tree node
struct node
{
    int value;
    struct node* left;
    struct node* right;
    int ht;
};
 
// global initialization of root node
struct node* root = NULL;
 
// function prototyping
struct node* create(int);
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* rotate_left(struct node*);
struct node* rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*);
 
int main()
{
    int user_choice, value;
    struct node* result = NULL;
 
    while (true)
    {
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder");
        printf("\n4. EXIT");
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice)
        {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
 
            case 2:
                printf("\nEnter value: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;

            case 3:
            printf("Output AVL tree nodes :");
                inorder(root);
                break;

            case 4:
                printf("\n\tProgram Terminated\n");
                return 1;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
    }
 
    return 0;
}
 
// creates a new tree node
struct node* create(int value)
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
 
    // if a memory error has occurred
    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
 
// rotates to the left
struct node* rotate_left(struct node* root)
{
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
 
    // return the new node after rotation
    return right_child;
}
 
// rotates to the right
struct node* rotate_right(struct node* root)
{
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
 
    // return the new node after rotation
    return left_child;
}
 
// calculates the balance factor of a node
int balance_factor(struct node* root)
{
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
 
// calculate the height of the node
int height(struct node* root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
 
    if (lh > rh)
        return (lh);
    return (rh);
}
 
// inserts a new node in the AVL tree
struct node* insert(struct node* root, int value)
{
    if (root == NULL)
    {
        struct node* new_node = create(value);
        if (new_node == NULL)
        {
            return NULL;
        }
        root = new_node;
    }
    else if (value > root->value)
    {
        // insert the new node to the right
        root->right = insert(root->right, value);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == -2)
        {
            if (value > root->right->value)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        // insert the new node to the left
        root->left = insert(root->left, value);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == 2)
        {
            if (value < root->left->value)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    // update the heights of the nodes
    root->ht = height(root);
    return root;
}
 
// deletes a node from the AVL tree
struct node * delete(struct node *root, int x)
{
    struct node * temp = NULL;
 
    if (root == NULL)
    {
        return NULL;
    } 
 
    if (x > root->value)
    {
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2)
        {
            if (balance_factor(root->left) >= 0)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->value)
    {
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2)
        {
            if (balance_factor(root->right) <= 0)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        { 
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
 
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                {
                    root = rotate_right(root);
                }
                else
                {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}

// inorder traversal of the tree
void inorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
 
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}