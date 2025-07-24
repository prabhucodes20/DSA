#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BinaryTree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Create tree using level-order (BFS) input
    void create() {
        int val;
        cout << "Enter root value (-1 for NULL): ";
        cin >> val;

        if (val == -1) return;

        root = new Node(val);
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            int leftVal, rightVal;
            cout << "Enter left child of " << current->data << " (-1 for NULL): ";
            cin >> leftVal;
            if (leftVal != -1) {
                current->left = new Node(leftVal);
                q.push(current->left);
            }

            cout << "Enter right child of " << current->data << " (-1 for NULL): ";
            cin >> rightVal;
            if (rightVal != -1) {
                current->right = new Node(rightVal);
                q.push(current->right);
            }
        }
    }
    void createRecursive(Node*& node) {
        int val;
        cout << "Enter value (-1 for NULL): ";
        cin >> val;

        if (val == -1) {
            node = nullptr;
            return;
        }

        node = new Node(val);
        cout << "Creating left child of " << val << endl;
        createRecursive(node->left);
        cout << "Creating right child of " << val << endl;
        createRecursive(node->right);
    }
    // Traversals
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.create();
    // Alternatively, you can use the recursive method
    // tree.createRecursive(tree.root);
    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    return 0;
}
