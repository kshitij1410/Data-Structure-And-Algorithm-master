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


//time -O(3*N)
//space -O(4*N)
void singleTraversal(struct Node *root)
{
    vector<int> preorder, post, inorder;
    if (root == NULL)
        return;

    stack<pair<struct Node *, int>> st;

    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // come under preorder
        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            st.push({it.first, it.second + 1});

            // check their left
            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            st.push({it.first, it.second + 1});

            // check their right
            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }

    for (auto ele : preorder)
        cout << ele << " ";
    cout << endl;
    for (auto ele : inorder)
        cout << ele << " ";
    cout << endl;
    for (auto ele : post)
        cout << ele << " ";
        
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

    singleTraversal(root);
    return 0;
}
