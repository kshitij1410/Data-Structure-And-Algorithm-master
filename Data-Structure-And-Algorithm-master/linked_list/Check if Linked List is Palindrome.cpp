//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
Node *reverse_ll(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while (p)
    {
        // store the curr index
        q = p;
        // move p forwar
        p = p->next;
        // link the prev
        q->next = r;

        // move r forward;
        r = q;
    }

    return q;
}

class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head == NULL or head->next == NULL)
            return true;

        Node *s = head;
        Node *f = head;

        // find the middle element
        while (f->next and f->next->next)
        {
            s = s->next;
            f = f->next->next;
        }

        // reverse the second half
        s->next = reverse_ll(s->next);

        // move to second half and compare with first half
        s = s->next;

        while (head and s)
        {
            if (head->data != s->data)
                return false;
            head = head->next;
            s = s->next;
        }

        return true;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends