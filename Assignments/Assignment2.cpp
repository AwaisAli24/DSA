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
class Stack{
    Node* top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int d){
        Node* newNode=new Node(d);
        if(top==NULL){
            top=newNode;
            return;
        }
        newNode->next=top;
        top=newNode;
    }
    int peek(){
        return top->data;
    }
    int pop(){
        if(top==NULL){
            cout<<"Stack is empty.";
            return 0;
        }
        Node* temp=top;
        top=top->next;
        return temp->data;
    }
};
int main(){
    Stack s;
    s.pop();
    return 0;
}