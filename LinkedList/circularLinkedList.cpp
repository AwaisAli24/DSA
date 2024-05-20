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
    Node* tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void addNode(int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            tail->next=head;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        tail->next=head;
    }
    void printList(){
        Node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    void josephus(int n){
        Node* curr=head;
        Node* prev=NULL;
        while(curr->next!=curr){
            for(int i=0;i<n-1;i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            Node* temp=curr;
            curr=curr->next;
            delete temp;
        }
        head=curr;
    }
    void printReverse(){
        int length=10;
        for(int i=0;i<length;i++){
            Node* temp=head;
            for(int j=1;j<length-i;j++){
                temp=temp->next;
            }
            cout<<temp->data<<" ";
        }
    }
};
int main(){
    LinkedList l;
    l.addNode(1);
    l.addNode(2);
    l.addNode(3);
    l.addNode(4);
    l.addNode(5);
    l.addNode(6);
    l.addNode(7);
    l.addNode(8);
    l.addNode(9);
    l.addNode(10);
    // l.josephus(3);
    // l.printList();
    l.printReverse();
    return 0;
}