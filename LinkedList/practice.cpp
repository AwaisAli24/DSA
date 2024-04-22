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
        Node* temp
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
    return 0;
}