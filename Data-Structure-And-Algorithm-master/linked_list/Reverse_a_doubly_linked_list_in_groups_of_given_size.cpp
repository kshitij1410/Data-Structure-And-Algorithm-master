#include <iostream>
using namespace std;
struct Node {
	int data;
	Node *next, *prev;
};

Node* insertAtEnd(Node* head, int data)
{

	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	Node* temp = head;
	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		return head;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	return head;
}
// function to print Doubly LinkedList
void printDLL(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
// function to Reverse a doubly linked list
// in groups of given size
Node* reverseByN(Node* head, int k)
{
	if (!head)
		return NULL;
	 Node *p=head,*q=NULL,*r=NULL;
     int d=k;
     while (p and d--)
     {
        q=p;
        p=p->next;
        q->prev=p;
        q->next=r;
        r=q;
     }

     q->prev=NULL;
     head->next=reverseByN(p,k);
     return q;
     
}
int main()
{
	Node* head;
	for (int i = 1; i <= 4; i++) {
		head = insertAtEnd(head, i);
	}
	printDLL(head);
	int n = 2;
	head = reverseByN(head, n);
	printDLL(head);
	return 0;
}