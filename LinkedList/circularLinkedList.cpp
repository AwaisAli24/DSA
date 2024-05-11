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
    void josephus(){
        for(int i=0;i<9;i++){
            Node* temp1=head;
            Node* temp2=NULL;
            for(int i=1;i<3;i++){
                temp2=temp1;
                temp1=temp1->next;
            }
            if(temp1==head){
                head=head->next;
            }
            temp2=temp1->next;
            delete temp1;
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
    l.josephus();
    // l.printList();
    return 0;
}