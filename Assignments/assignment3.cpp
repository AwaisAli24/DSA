#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
Node* newNode(int key){
    Node* temp=new Node(key);
    return temp;
}
Node* insert(Node* root,int key){
    if(root==NULL){
        return newNode(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else if(key>root->key){
        root->right=insert(root->right,key);
    }
    return root;
}
Node* search(Node* root,int key){
    if(root==NULL||root->key==key){
        return root;
    }
    if(key<root->key){
        return search(root->left,key);
    }
    
    return search(root->right,key);
}
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->key<<" ";
        inOrder(root->right);
    }
}
void preOrder(Node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->key<<" ";
    }
}

int main(){
    Node* root=NULL;
    root=insert(root,9);
    insert(root,8);
    insert(root,15);
    insert(root,3);
    insert(root,6);
    insert(root,2);
    insert(root,19);
    insert(root,23);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    Node* result=search(root,20);
    if(result!=NULL){
        cout<<"Value found."<<endl;
    }
    else{
        cout<<"Value not found"<<endl;
    }
    return 0;
}