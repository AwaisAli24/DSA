#include"LinkedList.h"
using namespace std;
int middleElement(LinkedList l){
    Node* temp1=l.head;
    Node* temp2=l.head;
    while(temp2!=NULL&&temp2->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    return temp1->value;
}
int main(){
    LinkedList l;
    l.addNode(1);
    l.addNode(2);
    l.addNode(3);
    l.addNode(4);
    l.addNode(5);

    cout<<middleElement(l);
}