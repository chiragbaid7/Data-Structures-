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
void insertAtTail(Node *&head,int data)
{
    Node *temp=head;  //Pointer holding the same head address and life line is within this function as no mem wastage 
    while(temp->next!=NULL)//preserve the node
    {
        temp=temp->next;
    }
    Node *node=new Node(data);
    temp->next=node;
}
int lengthLinkedList(Node *head)
{
    int length=0;
    while(head!=NULL)
    {
        length++;
        head=head->next;
    }
    return length;
}
void InsertatMiddle(Node*&head,int data,int p)
{
    //create a node
    if(head==NULL || p==0)
    {
        insertAtHead(head,data);
    }   
    //more than length of linkedlist
    else if(p>lengthLinkedList(head))
    {
        insertAtTail(head,data);
    }   
    else 
    {
        int i=1;//insert after head node
        Node *temp=head;
        while(i!=p)
        {
            i++;
            temp=temp->next;
        }
        Node *node=new Node(data);
        node->next=temp->next;
        temp->next=node;
    }
}
//pass by pointer(value)
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }   
}
void deleteAtHead(Node *&head)
{
    Node *temp=head;
    head=head->next;
    delete temp;
}
void deleteAtTail(Node *&head)
{
    Node *temp=head;
    Node *prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
}
void deleteAtMiddle(Node *&head,int key)
{
    if(key==0)
    {
        deleteAtHead(head);
    }
    //one more condition for Tail end
    else 
    {
        int i=1;
        Node *temp = head; //with this technique you are allowed to go inside the memory and change globally
        Node *prev=NULL;
        while(i<=key)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        delete temp;
    }
}
bool search(Node *head,int key)
{
    while(head!=NULL)
    {
        if(head->data=key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}
ostream& operator<<(ostream &os,Node *head)
{
    print(head);
    return os;
}
Node* recursivereverse(Node *head)
{
    //base case
    //1.return head if null or no head 
    if(head->next==NULL || head==NULL)
    {
        return head;
    }
    Node *smallhead=recursivereverse(head->next);
    Node *c=head;
    c->next->next=c;
    c->next=NULL;
    return smallhead;
}
void reverse(Node *&head)
{
    Node *p=NULL;
    Node *c=head;
    Node *n=NULL;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p; 
}
//Runner Technique-To find mid point of a node
Node* midpoint(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //slow pointer 
    //fast pointer 
    Node* slow=head;
    Node *fast=head->next;
    //current node and the next node should not be equal to null
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main()
{
    Node* head=NULL;
    insertAtHead(head,4);
    //insertAtHead(head,10);
    //insertAtHead(head,11);
    //InsertatMiddle(head,23,1);
    //InsertatMiddle(head, 63, 3);
    insertAtTail(head,44);
    insertAtTail(head, 100);  
    
    //deleteAtHead(head);
    //deleteAtMiddle(head,3);
    cout<<head;
    cout<<"\n";
    //cout << search(head, 10);        
    Node *newhead=recursivereverse(head);
    cout << newhead<<endl;
    cout<<midpoint(newhead)->data;
}