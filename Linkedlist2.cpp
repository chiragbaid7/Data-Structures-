#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    //constructor
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
//Passing by pointer reference
void insertAtHead(Node*&head,int data)
{
   Node *node=new Node(data);
   node->next=head;
   head=node; 
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void print_k_node_end(Node *head,int k)
{
    Node *fast=head;
    Node *slow=head;
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    cout<<slow->data;
}
int main()
{
    Node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,10);
    insertAtHead(head,11);
    insertAtHead(head,12);
    insertAtHead(head,13);
    insertAtHead(head, 63);
    insertAtHead(head, 43);
    print(head);
    cout<<"\n";
    print_k_node_end(head,3);
}