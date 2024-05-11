#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d=0){
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
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    return 0;
}