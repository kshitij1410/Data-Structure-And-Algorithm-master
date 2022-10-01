//{ Driver Code Starts
// Initial template for C++

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *addOne(Node *head)
    {
        Node *curr = head;
        while (curr and curr->next)
        {
            curr = curr->next;
        }
        // last node
        if (curr->data != 9)
        {
            curr->data += 1;
            return head;
        }
        else
        {
            Node *temp = head;

            // last node is 9

            int index = -1; // check if any element is less than 9 or not
            int count = 0;
            while (temp)
            {

                count++;
                if (temp->data != 9)
                {
                    index = count;
                }
                temp = temp->next;
            }

            if (index == -1)
            {
                // case1: if all node is 9 then append one node
                Node *new_node = new Node(1);
                Node *temp = head;

                while (temp)
                {
                    temp->data = 0;
                    temp = temp->next;
                }

                new_node->next = head;
                head = new_node;
                return head;
            }
            else
            {
                // case2: otherwise add 1 whose value is not 9 and which is last and after than all node is 0 ex- 9899 => 9900 , 9893 => 9894
                Node *t = head;
                int c = 0;
                while (t)
                {
                    c++;

                    if (index == c)
                    {
                        t->data += 1;
                    }
                    if (index < c)
                    {
                        t->data = 0;
                    }
                    t = t->next;
                }

                return head;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends