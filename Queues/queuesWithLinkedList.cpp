#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Queue{
    Node* rear;
    Node* front;
    public:
    Queue(){
        front=rear=NULL;
    }
    void enqueue(int d){
        Node* newNode=new Node(d);
        if(front==NULL){
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }
    int dequeue(){
        Node* temp=front;
        front=front->next;
        int n=temp->data;
        delete temp;
        return n;
    }
    void print(){
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    q.print();
    return 0;
}