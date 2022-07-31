#include <bits/stdc++.h>
using namespace std;

struct BT {
    int data;
    BT* left;
    BT* right;
    BT(int data) : data(data), left(NULL), right(NULL){};
};

struct BST {
    BT* root;

    void printTree(BT* root) {
        if (!root) return;

        cout << root->data << " : ";
        if (root->left) {
            cout << "L" << root->left->data << " ";
        }
        if (root->right) {
            cout << "R" << root->right->data << " ";
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    return 0;
}