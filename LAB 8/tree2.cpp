#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        return node;
    }

    void print_tree(Node* node, int space = 0, int indent = 5) const {
        if (!node) return;
        space += indent;
        print_tree(node->right, space);
        cout << endl;
        for (int i = indent; i < space; i++) cout << " ";
        cout << node->value << "\n";
        print_tree(node->left, space);
    }

    void search(Node* node, int value) const {
        if (!node) {
            cout << "Value " << value << " not found in the tree.\n";
            return;
        }
        cout << "Visiting: " << node->value << endl;
        if (value == node->value)
            cout << "Found value: " << value << endl;
        else if (value < node->value)
            search(node->left, value);
        else
            search(node->right, value);
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void display_tree() const {
        cout << "\nTree structure (sideways view):\n";
        print_tree(root);
    }

    void search(int value) const {
        cout << "\nSearching for value " << value << "...\n";
        search(root, value);
    }
};

int main() {
    BST tree;

    // Insert nodes: 4, 2, 6, 1, 3, 5, 7 (creates balanced BST)
    int values[] = {4, 2, 6, 1, 3, 5, 7};
    for (int val : values) {
        tree.insert(val);
    }

    tree.display_tree();

    // Search for value 5
    tree.search(5);

    return 0;
}
