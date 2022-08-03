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

void IterativeInorder(struct Node *root)
{
    if (root == NULL)
        return;

    stack<struct Node *> st;
    struct Node *temp = root;

    while (temp != NULL or !st.empty() )
    {
        // push all left child
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        struct Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // move to right
        if (curr->right)
            temp = curr->right;

    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    IterativeInorder(root);
    return 0;
}
