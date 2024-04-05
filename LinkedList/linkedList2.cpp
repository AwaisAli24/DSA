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
    void deleteNode(int noOfNode){
        if(head==NULL){
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp1=head,*temp2=NULL;
        int length=1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            length++;
        }
        if(length<noOfNode){
            cout<<"Index out of order."<<endl;
            return;
        }
        temp1=head;
        if(noOfNode==1){
            head=head->next;
            delete temp1;
            return;
        }
        while(noOfNode-- >1){
            temp2=temp1;
            temp1=temp1->next;

        }
        temp2->next=temp1->next;
        delete temp1;
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.printList();
    list.deleteNode(3);
    list.printList();
    return 0;
}
