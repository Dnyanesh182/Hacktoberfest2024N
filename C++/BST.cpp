#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Helper function to insert a new node into the BST
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    // Helper function to perform an inorder traversal of the BST
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Helper function to search for a value in the BST
    bool searchNode(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    // Helper function to find the minimum value node in the BST
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        // Traverse to the left or right depending on the value
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    // Constructor to initialize an empty BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a new value in the BST
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public function to perform an inorder traversal of the BST
    void inorder() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Public function to search for a value in the BST
    bool search(int value) {
        return searchNode(root, value);
    }

    // Public function to delete a node from the BST
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST bst;

    // Insert nodes into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Display the BST using inorder traversal
    bst.inorder();

    // Search for a value in the BST
    int value = 40;
    std::cout << "Searching for " << value << " in the BST: ";
    std::cout << (bst.search(value) ? "Found" : "Not Found") << std::endl;

    // Delete a value from the BST
    bst.deleteValue(20);
    std::cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    return 0;
}
