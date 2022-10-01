#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int v)
    {
        data = v;
        next = NULL;
    }
};

Node *reverse_ll(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    int temp = k;

    while (p and temp > 0)
    {
        // store the curr index
        q = p;
        // move p forwar
        p = p->next;
        // link the prev
        q->next = r;

        // move r forward;
        r = q;
        temp--;
    }

    head->next = reverse_ll(p, k);
    return q;
}

Node *insertEle(int arr[], Node *head, int n)
{
    if (n == 0)
        return NULL;

    if (head == NULL)
    {
        Node *temp = new Node(arr[0]);
        head = temp;
    }

    Node *curr = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }

    return head;
}

void print(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr[i] = val;
    }

    Node *head = NULL;

    head = insertEle(arr, head, n);
    print(head);
    cout << "\n";
    int k = 4;
    head = reverse_ll(head, k);
    print(head);

    return 0;
}