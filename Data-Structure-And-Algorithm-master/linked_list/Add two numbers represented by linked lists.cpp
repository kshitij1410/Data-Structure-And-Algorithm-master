//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


class Solution
{
public:
    struct Node *addition(Node *temp1, Node *temp2, int size1,
                          int size2)
    {
        // creating a new Node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        // base case
        if (temp1->next == NULL && temp2->next == NULL)
        {
            // addition of current nodes which is the last nodes
            // of both linked lists
            newNode->data = (temp1->data + temp2->data);

            // set this current node's link null
            newNode->next = NULL;

            // return the current node
            return newNode;
        }

        // creating a node that contains sum of previously added
        // number
        struct Node *returnedNode = (struct Node *)malloc(sizeof(struct Node));

        // if sizes are same then we move in both linked list
        if (size2 == size1)
        {
            // recursively call the function
            // move ahead in both linked list
            returnedNode = addition(temp1->next, temp2->next,
                                    size1 - 1, size2 - 1);

            // add the current nodes and append the carry
            newNode->data = (temp1->data + temp2->data) + ((returnedNode->data) / 10);
        }
        // or else we just move in big linked list
        else
        {
            // recursively call the function
            // move ahead in big linked list
            returnedNode = addition(temp1, temp2->next, size1,
                                    size2 - 1);

            // add the current node and carry
            newNode->data = (temp2->data) + ((returnedNode->data) / 10);
        }

        // this node contains previously added numbers
        // so we need to set only rightmost digit of it
        returnedNode->data = (returnedNode->data) % 10;

        // set the returned node to the current node
        newNode->next = returnedNode;

        // return the current node
        return newNode;
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *head1, struct Node *head2)
    {
        struct Node *temp1, *temp2, *ans = NULL;

        temp1 = head1;
        temp2 = head2;

        int size1 = 0, size2 = 0;

        // calculating the size of first linked list
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            size1++;
        }
        // calculating the size of second linked list
        while (temp2 != NULL)
        {
            temp2 = temp2->next;
            size2++;
        }

        struct Node *returnedNode = (struct Node *)malloc(sizeof(struct Node));

        // traverse the bigger linked list
        if (size2 > size1)
        {
            returnedNode = addition(head1, head2, size1, size2);
        }
        else
        {
            returnedNode = addition(head2, head1, size2, size1);
        }

        // creating new node if head node is >10
        if (returnedNode->data >= 10)
        {
            ans = (struct Node *)malloc(sizeof(struct Node));
            ans->data = (returnedNode->data) / 10;
            returnedNode->data = returnedNode->data % 10;
            ans->next = returnedNode;
        }
        else
            ans = returnedNode;

        // return the head node of linked list that contains
        // answer
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends