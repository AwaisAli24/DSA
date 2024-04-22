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
    }
};
int main(){

    return 0;
}