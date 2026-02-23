#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *minVal(Node *root) {
    Node *current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deleteInBST(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteInBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteInBST(root->right, key);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }else{
        Node *temp = minVal(root->right);
        root->data = temp->data;
        root->right= deleteInBST(root->right, temp->data);
    	}
    }
    return root;
}

int main() {
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;
    root = deleteInBST(root, 4);
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}

