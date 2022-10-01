//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    Node *findMid(Node *head)
    {
        Node *s = head;
        Node *f = head->next;
        while (f and f->next)
        {
            s = s->next;
            f = f->next->next;
        }

        return s;
    }

    Node *merge(Node *left, Node *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        Node *dumi = new Node(0);
        Node *curr = dumi;

        while (left and right)
        {
            if (left->data < right->data)
            {
                curr->next = left;
                curr = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                curr = right;
                right = right->next;
            }
        }

        if (left)
            curr->next = left;
        if (right)
            curr->next = right;

        dumi = dumi->next;
        return dumi;
    }

    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // break linked list into 2 halvs, after finding mid
        Node *mid = findMid(head);

        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;

        // recursive calls to sort both halves
        left = mergeSort(left);
        right = mergeSort(right);

        // merge both left and right halves
        Node *result = merge(left, right);

        return result;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends