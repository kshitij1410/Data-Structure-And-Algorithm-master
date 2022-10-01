#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int v)
    {
        data=v;
        next=NULL;
    }
};


void insertNode(Node * &head,int data)
{
    Node *node = new Node(data);

    if(head==NULL)
    {
        head=node;
        return;
    }
    Node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
    return;
    
}

void dispay(Node *head)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    Node * head=NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    dispay(head);
    return 0;
}