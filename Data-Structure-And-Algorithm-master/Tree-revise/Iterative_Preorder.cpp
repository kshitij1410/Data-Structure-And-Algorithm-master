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

// space -O(n) // time-O(n)
void IterativePreorder(struct Node *root)
{
    if (root == NULL)
        return;

    stack<struct Node *> st;
    st.push(root);

    while (!st.empty())
    {
        struct Node *temp = st.top();
        st.pop();
        cout << temp->data << " ";

        if (temp->right)
            st.push(temp->right);

        if (temp->left)
            st.push(temp->left);
    }
}

// space O(h) and time- O(n)

void IterativePreorder1(struct Node *root)
{
    if (root == NULL)
        return;

    stack<struct Node *> st;
    struct Node *curr = root;

    while (curr != NULL or !st.empty())
    {
        // traverse only left
        while (curr)
        {
            if (curr->right)
                st.push(curr->right);

            cout << curr->data << " ";
            curr = curr->left;
        }

        if (st.size() > 0)
        {
            curr = st.top();
            st.pop();
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

    IterativePreorder(root);
    cout<<endl;
    IterativePreorder1(root);
    return 0;
}
