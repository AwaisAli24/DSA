#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
private:
    vector<int> tree;
    int capacity;

public:
    // Constructor to initialize the binary tree with a given capacity
    BinaryTree(int cap) : capacity(cap) {
        tree.resize(capacity, -1); // Initialize all elements to -1 indicating empty slots
    }

    // Insert a value into the binary tree
    void insert(int value) {
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] == -1) {
                tree[i] = value;
                return;
            }
        }
        cout << "Binary Tree is full. Cannot insert " << value << endl;
    }

    // In-order traversal to print the elements
    void inOrderTraversal(int index) {
        if (index >= capacity || tree[index] == -1)
            return;

        inOrderTraversal(2 * index + 1); // Visit left child
        cout << tree[index] << " "; // Visit node
        inOrderTraversal(2 * index + 2); // Visit right child
    }

    // Function to start in-order traversal from the root
    void inOrder() {
        inOrderTraversal(0); // Start from root (index 0)
        cout << endl;
    }
};

int main() {
    int capacity = 15; // Define the capacity of the binary tree
    BinaryTree bt(capacity);

    // Insert elements into the binary tree
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    // Print elements of the binary tree using in-order traversal
    cout << "In-order traversal of the binary tree: ";
    bt.inOrder();

    return 0;
}
