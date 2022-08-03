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

void IterativePostorder(struct Node *root)
{
    if (root == NULL)
        return;

    stack<struct Node *> st;
    struct Node *temp = root;

    while (temp != NULL or !st.empty())
    {
        if (temp != NULL)
        {
            // move left
            while (temp)
            {
                st.push(temp);
                temp = temp->left;
            }
        }
        else
        {
            struct Node *curr = st.top()->right;

            if (curr)
            {
                temp = curr;
            }
            else
            {

                while (!st.empty() and st.top()->right == curr)
                {
                    cout << st.top()->data << " ";
                    curr = st.top();
                    st.pop();
                }
            }
        }
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

    IterativePostorder(root);
    return 0;
}
