#include "LinkedList.h"
void LinkedList::reverse(){
    Node* current=head;
    Node* next=current->next;
    Node* prev=NULL;

    while(current!=NULL){
        current->next=prev;
        prev=current;
        current=next;
        next=next->next;
    }
    head=prev;
}
int main(){
    LinkedList l1;
    l1.addNode(1);
    l1.addNode(2);
    l1.addNode(3);
    l1.addNode(4);
    l1.addNode(5);
    l1.printList();
    l1.reverse();
    l1.printList();
}