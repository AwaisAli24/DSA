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
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
//Inserting Node
    void insertNode(int d){
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
    }
//Printing the list
    void printList(){
        if(head==NULL){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
//Deleteing a node at a specific postion
    void deleteNode(int n){
        Node* temp1=head;
        Node* temp2=NULL;
        if(n==1){
            head=head->next;
            delete temp1;
            return;
        }
        int length=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            length++;
        }
        temp1=head;
        if(n>length){
            cout<<"Index out of range."<<endl;
            return;
        }
        for(int i=1;i<n;i++){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        delete temp1;
    }
//Inserting node after a specific node
    void insertNodeAt(int d,int n){
        Node* newNode=new Node(d);
        Node* temp=head;
        for(int i=1;i<n;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
//sorting a linkedlist
    void sort(){
        Node* temp1=head;
        int temp;
        while(temp1!=NULL){
            Node* temp2=temp1->next;
            while(temp2!=NULL){
                if(temp2->data<temp1->data){
                    temp=temp1->data;
                    temp1->data=temp2->data;
                    temp2->data=temp;
                }
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
    }
};
int main(){
    LinkedList l;
    l.insertNode(2);
    l.insertNode(5);
    l.insertNode(1);
    l.insertNode(9);
    l.insertNode(4);
    l.printList();
    l.insertNodeAt(5,1);
    l.printList();
    l.sort();
    l.printList();
    return 0;
}