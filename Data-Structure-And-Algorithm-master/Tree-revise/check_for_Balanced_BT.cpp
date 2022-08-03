#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int height(struct Node *temp)
{
    if (temp == NULL)
        return 0;

    int hl = height(temp->left);
    int hr = height(temp->right);

    return max(hl, hr) + 1;
}

// time -O(N *N) for n for each node and n for calcualting height at each node

bool checkForBalancedTree(struct Node *root)
{
    if (root == NULL)
        return true;

    int hl = height(root->left);
    int hr = height(root->right);

    if (abs(hl - hr) > 1)
        return false;

    bool c1 = checkForBalancedTree(root->left);
    bool c2 = checkForBalancedTree(root->right);

    if (c1 and c2)
        return true;
    else
        return false;
}



// time-O(N)
int ishelperisBalancedTree1(struct Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int hl = ishelperisBalancedTree1(root->left);
    int hr = ishelperisBalancedTree1(root->right);

    if (hl == -1 or hr == -1)
        return -1;
    if (abs(hl - hr) > 1)
        return -1;
    else
        return max(hl, hr) + 1; // otherwise it return height of tree
}


bool checkForBalancedTreeOpt(struct Node *root)
{
    int result = ishelperisBalancedTree1(root);
    if (result == -1)
        return false;
    else
        return true;
}

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(4);
    root->right = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(70);
    root->right->left = new Node(13);
    cout << checkForBalancedTree(root) << endl;
    cout << checkForBalancedTreeOpt(root);
    return 0;
}
