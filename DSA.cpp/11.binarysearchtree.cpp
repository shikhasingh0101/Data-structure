//  Implement binary Search Tree ADT using Linked List.
#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    
    BinarySearchTree() {
        root = nullptr;
    }

 
    ~BinarySearchTree() {
        clear(root);
    }

    void clear(TreeNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }


    bool isEmpty() {
        return root == nullptr;
    }

   
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }


    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;


    int numElements;
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;

    int element;
    cout << "Enter the elements to insert: ";
    for (int i = 0; i < numElements; ++i) {
        cin >> element;
        bst.insert(element);
    }

    cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();


    int searchElement;
    cout << "Enter the element to search: ";
    cin >> searchElement;
    cout << "Searching for " << searchElement << ": " << (bst.search(searchElement) ? "Found" : "Not found") << endl;

    return 0;
}
