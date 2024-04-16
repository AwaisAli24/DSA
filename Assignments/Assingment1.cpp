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
    void friend commonElements(LinkedList,LinkedList);
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
    if(n>length){
        cout<<"Index out of range"<<endl;
        return;
    }
    temp1=head;
    while(n-->1){
        temp1=temp1->next;
    }
    newNode->next=temp1->next;
    temp1->next=newNode;
    return;
}
void commonElements(LinkedList l1,LinkedList l2){
    Node *temp1=l1.head;
    Node *temp2=l2.head;
    while(temp1!=NULL){
        temp2=l2.head;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                cout<<temp1->data<<" is common."<<endl;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
int main(){
    LinkedList l1;
    l1.insertNode(1);
    l1.insertNode(2);
    l1.insertNode(3);
    l1.insertNode(4);
    l1.insertNode(5);
    // l.insertNodeAt(23,1);
    l1.printList();
    LinkedList l2;
    l2.insertNode(4);
    l2.insertNode(5);
    l2.insertNode(6);
    l2.insertNode(7);
    l2.insertNode(8);
    l2.printList();
    commonElements(l1,l2);
    return 0;
}