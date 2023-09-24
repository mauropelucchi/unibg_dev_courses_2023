/*

Given a binary tree, we need to write a program (with recursive function) 
to print all leaf nodes 
of the given binary tree from left to right.

Main steps:
1) Check if the given node is null. If null, then return from the function.
2) Check if it is a leaf node. If the node is a leaf node, then print its data.
3) If in the above step, the node is not a leaf node then check if the 
left and right children of node exist. If yes then call the function 
or left and right child of the node recursively.

Example of struct for a node:

typedef struct node 
{ 
    int data; 
    Node *left, *right; 
} Node;

Utility function to create a new tree node:
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

*/

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

void print_leaf(Node *root);
void print_all_nodes(Node *root);
Node *newNode(int data);

int main()
{

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    print_leaf(root);
    print_all_nodes(root);

    return 0;
}

void print_leaf(Node *root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
        print_leaf(root->left);

    if (root->right)
        print_leaf(root->right);
}

void print_all_nodes(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";

    if (root->left)
        print_all_nodes(root->left);
    if (root->right)
        print_all_nodes(root->right);
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}