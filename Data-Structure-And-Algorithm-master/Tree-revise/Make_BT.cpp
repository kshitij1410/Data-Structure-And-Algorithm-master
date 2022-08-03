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

int main()
{
  struct Node *root = NULL;
  root = make_BT();
  inorder(root);
  return 0;
}
