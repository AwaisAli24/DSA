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
    LinkedList friend commonElements(LinkedList,LinkedList);
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
    while(temp1!=NULL){
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
    for(int i=1;i<n;i++){
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
    for(int i=1;i<n;i++){
        temp1=temp1->next;
    }
    newNode->next=temp1->next;
    temp1->next=newNode;
    return;
}
LinkedList commonElements(LinkedList l1,LinkedList l2){
    LinkedList l3;
    Node *temp1=l1.head;
    Node *temp2=l2.head;
    while(temp1!=NULL){
        temp2=l2.head;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                l3.insertNode(temp1->data);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return l3;
}
int main(){
    LinkedList l1;
    l1.insertNode(4);
    l1.insertNode(12);
    l1.insertNode(43);
    l1.insertNode(9);
    l1.insertNode(7);
    l1.insertNode(18);
    l1.deleteNodeAt(3);
    l1.printList();

    LinkedList l2;
    l2.insertNode(6);
    l2.insertNode(2);
    l2.insertNode(9);
    l2.insertNode(1);
    l2.insertNodeAt(18,1);
    l2.printList();

    LinkedList l3=commonElements(l1,l2);
    l3.printList();
    return 0;
}