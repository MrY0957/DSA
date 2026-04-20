#include <bits/stdc++.h> // This header includes all standard libraries
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int choice;
    while(true) {
        cout << "\n--- Tree Traversal Menu ---\n";
        cout << "1. Preorder Traversal\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Level Order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Level Order: ";
                levelOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
