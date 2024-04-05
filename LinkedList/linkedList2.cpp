#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    public:
    Node(){
        value=0;
        next=NULL;
    }
    Node(int value){
        this->value=value;
        next=NULL;
    }
};
class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head=NULL;
    }
    void addNode(int v){
        Node* newNode=new Node(v);
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
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    LinkedList list;
    list.addNode(5);
    list.addNode(4);
    list.addNode(3);
    list.addNode(2);
    list.printList();
    return 0;
}
