#include<iostream>
#include<cmath>
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
    public:
    Node *head;
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
void func(LinkedList &l1,LinkedList &l2){
    Node* temp=l1.head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    for(int i=0;i<length;i++){
        temp=l1.head;
        for(int j=1;j<length-i;j++){
            temp=temp->next;
        }
        l2.addNode(temp->value);
    }
}
void func2(int n,int x){
    LinkedList list;
    for(int i=1;i<x;i++){
        list.addNode(pow(n,i));
    }
    list.printList();
}
int main(){
    //1st Question
    LinkedList list1,list2;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list1.addNode(4);
    list1.addNode(5);
    func(list1,list2);
    list2.printList();
    //2nd question
    int number,power;
    cout<<"Enter a number:";
    cin>>number;
    cout<<"Enter the power:";
    cin>>power;
    func2(number,power);
    return 0;
}
