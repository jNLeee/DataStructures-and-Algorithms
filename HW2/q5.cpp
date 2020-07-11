#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newnode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return (node);
}

int totalNodesofTwoChildren(struct Node* node)
{
    if (!node)
    {
        return 0;
    }
    queue <Node*> q;
    int count = 0;
    q.push(node);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();
        if (temp->left && temp->right)
        {
            count++;
        }
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }

    return count;
}

int main()
{
    struct Node *root = newnode(4);
    root->left = newnode(8);
    root->right = newnode(10);
    root->left->right = newnode(2);
    root->left->right->left = newnode(3);
    root->left->right->right = newnode(5);
    root->right->right = newnode(6);
    root->right->right->left = newnode(9);
    root->right->right->right = newnode(1);

    cout << "The total amount of nodes with two children in the binary tree is: ";
    cout << totalNodesofTwoChildren(root);

    return 0;
}