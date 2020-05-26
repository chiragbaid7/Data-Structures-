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
Node* merge(Node *list1,Node *list2)
{
    if(list1==NULL)
    {
        return list2;
    }
    else if(list2==NULL)
    {
        return list1;
    }  
    Node *c;
    if(list1->data<list2->data)
    {
        c=list1;
        c->next = merge(list1->next, list2);
    }
    else 
    {
        c=list2;
        c->next=merge(list1,list2->next);
    }
    return c;
}
//given a linked list perform mergesort
Node *midpoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL || fast->next!=NULL)
    {
        fast = fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node *Mergesort(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //recusive sort
    Node *mid=midpoint(head);
    Node *a = head;
    Node *b=mid->next;
    mid->next=NULL;
    a=Mergesort(a);
    b=Mergesort(b);
    //Merge
    Node *c=merge(a,b);
    return c;
}
int main()
{
    Node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,10);
    insertAtHead(head,11);
    insertAtHead(head,12);
    insertAtHead(head,2);
    insertAtHead(head, 3);
    insertAtHead(head, 14);
    print(head);
    cout<<endl;
    Node *c=midpoint(head);
    print(c);
    
}