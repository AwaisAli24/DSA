#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int d){
        data=d;
        next=NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    void insertNode(int d);
    void deleteNodeAt(int n);
    void printList();
    void insertNodeAt(int d,int n);
};
void LinkedList::insertNode(int d){
    Node* newNode=new Node(d);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return;
}
void LinkedList::printList(){
    Node* temp=head;
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void LinkedList::deleteNodeAt(int n){
    if(head==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp1=head,*temp2=NULL;
    int length=0;
    while(temp1->next!=NULL){
        temp1=temp1->next;
        length++;
    }
    if(n>length){
        cout<<"Index out of order."<<endl;
        return;
    }
    temp1=head;
    if(n==1){
        head=head->next;
        delete temp1;
        return;
    }
    while(n-->1){
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=temp1->next;
    delete temp1;
}
void LinkedList::insertNodeAt(int d,int n){
    Node* newNode=new Node(d);
    Node* temp1=head;
    int length=0;
    while(temp1!=NULL){
        temp1=temp1->next;
        length++;
    }
    
}
int main(){
    LinkedList l;
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);
    l.insertNode(5);
    l.deleteNodeAt(6);
    l.printList();
    return 0;
}