/*
The following question was asked to the people who qualified the online coding 
challenge on Hackerearth and were invited for a interview / hackathon over slack with the Juspay team.

Part A

Given an n-ary tree of resources arranged hierarchically such that height of tree is O(Log N) where N 
is total number of nodes (or resources). A process needs to lock a resource node in order to use it. 
But a node cannot be locked if any of its descendant or ancestor is locked.

Following operations are required for a given resource node:
    Lock()- locks the given node if possible and updates lock information. 
            Lock is possible only if ancestors and descendants of current node are not locked.
    unLock()- unlocks the node and updates information.

How design resource nodes and implement above operations such that following time complexities are achieved.
    Lock() O(log N)
    unLock() O(log N)
*/

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
class Node
{
public:
    // Stores the key of the Node
    int key;
    // Stores the total count of locked descendants
    int lockedDescendantsCount;
    // Stores the locking information of the Node
    bool isLocked;
    // Stores the children of the Node
    vector<Node *> children;
    // Stores the parent information of the Node
    Node *parent;

    Node(Node *parent, int key);
};

Node::Node(Node *parent, int key)
{
    this->key = key;
    this->parent = parent;
    lockedDescendantsCount = 0;
    isLocked = false;
}

class NaryTree
{
private:
    // Keeps track of all the Nodes in the tree {key, Node*}
    unordered_map<int, Node *> AllNodes;
    // Root Node of our tree
    Node *root;

public:
    NaryTree(int key);
    void addNode(int parentKey, int Key);
    void lock(int key);
    void unlock(int key);
};

// Utility function to create Root Node
NaryTree::NaryTree(int key)
{
    root = new Node(NULL, key);
    AllNodes[key] = root;
}

// Utility function to add Nodes to the Parent
void NaryTree::addNode(int parentKey, int key)
{
    Node *curr = new Node(AllNodes[parentKey], key);
    AllNodes[key] = curr;
    AllNodes[parentKey]->children.push_back(curr);
}

// Utility function to lock a Node
void NaryTree::lock(int key)
{
    // Stores the Node corresponding to the key
    Node *curr;

    // If the Node corrsponding to the key is not found
    // return orelse store that Node
    if (AllNodes.find(key) == AllNodes.end())
    {
        cout << "is locked already !" << endl;
        return;
    }
    else
        curr = AllNodes[key];

    // If the Node is already locked, return
    if (curr->isLocked)
    {
        cout << "is locked already !" << endl;
        return;
    }

    // If our tree has descendants, It cannot be locked
    if (curr->lockedDescendantsCount > 0)
    {
        cout << "cannot be locked as it's descendants are locked" << endl;
        return;
    }

    // Traverse the ancestors of the current Node to verify that
    // Node of its ancestors is Locked
    Node *temp = curr->parent;
    while (temp)
    {
        if (temp->isLocked > 0)
        {
            cout << "cannot be locked as it's ancestor " << curr->key << " is locked" << endl;
            return;
        }

        temp = temp->parent;
    }

    // Lock the current Node
    curr->isLocked = true;

    // Travel its ancestors and increment the count
    // of locked descendants for all its ancestors by 1
    temp = curr->parent;
    while (temp)
    {
        temp->lockedDescendantsCount++;
        temp = temp->parent;
    }

    cout << "has been locked sucessfully !" << endl;
}

// Utility function to unlock a Node
void NaryTree::unlock(int key)
{
    // Stores the Node corresponding to the key
    Node *curr;

    // If the Node corrsponding to the key is not found
    // return orelse store that Node
    if (AllNodes.find(key) == AllNodes.end())
    {
        cout << "is not available, Please try again !" << endl;
        return;
    }
    else
        curr = AllNodes[key];

    // If the Node is already locked, return
    if (!curr->isLocked)
    {
        cout << "is unlocked already !" << endl;
        return;
    }

    // Unlock the current Node
    curr->isLocked = false;

    // Travel its ancestors and increment the count
    // of locked descendants for all its ancestors by 1
    Node* temp = curr->parent;
    while (temp)
    {
        temp->lockedDescendantsCount--;
        temp = temp->parent;
    }

    cout << "has been unlocked sucessfully !" << endl;
}

int main()
{
    /*   Let us create below tree
   *             1
   *         / /  \  \
   *       2  3   4    5
   *      / \     |  / |  \
   *     6  7     8  9 10 11
   *       /\           \
   *     12  13          14
   */
    NaryTree Tree(1);
    Tree.addNode(1, 2);
    Tree.addNode(1, 3);
    Tree.addNode(1, 4);
    Tree.addNode(1, 5);
    Tree.addNode(2, 6);
    Tree.addNode(2, 7);
    Tree.addNode(4, 8);
    Tree.addNode(5, 9);
    Tree.addNode(5, 10);
    Tree.addNode(5, 11);
    Tree.addNode(7, 12);
    Tree.addNode(7, 13);
    Tree.addNode(10, 14);
    
    cout << "Tree 4 ";
    Tree.lock(4);
    
    cout << "Tree 4 ";
    Tree.lock(4);

    cout << "Tree 3 ";
    Tree.lock(3);

    cout << "Tree 2 ";
    Tree.unlock(2);
    
    cout << "Tree 3 ";
    Tree.unlock(3);

    return 0;
}