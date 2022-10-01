#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int v)
    {
        data = v;
        next = NULL;
    }
};
int pairSum(Node *first, Node *last, int k)
{
    int ans = 0;
    while ((first) and first != last and first->prev != last)
    {
        int sum = first->data + last->data;

        if (sum < k)
        {
            first = first->next;
        }
        else if (sum > k)
        {
            last = last->prev;
        }
        else
        {
            ans++;
            first = first->next;
            last = last->prev;
        }
    }

    return ans;
}

int countTriplets(Node *head, int x)
{
    if (head == NULL)
        return 0;

    Node *last = head;
    while (last->next != NULL)
        last = last->next;

    Node *first = head;
    Node *second = head;
    int ans = 0;

    while (first->next != NULL)
    {
        second = first->next;
        Node *cpy_last = last;
        int k = x - first->data;
        ans += pairSum(second, cpy_last, k);
        first = first->next;
    }

    return ans;
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

    int x = 17;

    cout << "Count = " << countTriplets(head, x);

    return 0;
}