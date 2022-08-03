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

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

struct Node *make_BT()
{
    struct Node *temp;
    int data;

    cout << "Enter value of node" << endl;
    cin >> data;

    // terminate condition
    if (data == -1)
        return NULL;

    temp = new Node(data);

    cout << "Enter the left child of " << data << " " << endl;

    temp->left = make_BT();

    cout << "Enter the right child of " << data << " " << endl;

    temp->right = make_BT();

    return temp;
}

void level_order(struct Node *root)
{
    queue<struct Node *> q;
    if (root == NULL)
        return;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();

        if (temp == NULL and q.size() == 0)
            break;
        else if (temp == NULL and q.size() > 0)
        {
            cout<<"\n";
            q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            // left child
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    inorder(root);
    cout << "\n";
    level_order(root);
    return 0;
}
