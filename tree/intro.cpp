#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    vector<Tree *> children;
    Tree(int data) : data(data) {}
};

Tree *takeInput() {
    int rootData;
    cout << "Enter root dataa : ";
    cin >> rootData;

    Tree *root = new Tree(rootData);
    queue<Tree *> q;
    q.push(root);

    while (!q.empty()) {
        Tree *f = q.front();
        q.pop();

        int n;
        cout << "How many childrens of " << f->data << " ? " << endl;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int childData;
            cout << "Enter " << i << "th child data of " << f->data << " : ";
            cin >> childData;

            Tree *child = new Tree(childData);
            q.push(child);
            f->children.push_back(child);  //! NEEDED HELP HERE
        }
    }
    return root;
}

void printTree(Tree *root) {
    if (!root) return;

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }

    return;
}

int countNodes(Tree *root) {
    if (!root) return 0;
    int cnt = 1;
    for (int i = 0; i < root->children.size(); i++) {
        cnt += countNodes(root->children[i]);
    }
    return cnt;
}

int countLeaf(Tree *root) {
    if (!root) return 0;

    int leaf = 0;
    if (root->children.size() == 0) return 1;

    for (int i = 0; i < root->children.size(); i++) {
        leaf += countLeaf(root->children[i]);
    }
    return leaf;
}

int height(Tree *root) {
    if (!root) return 0;

    int maxx = 0;
    for (int i = 0; i < root->children.size(); i++) {
        maxx = max(maxx, height(root->children[i]));
        // cout << i << " : " << height(root->children[i]) << endl;
    }
    return maxx + 1;
}

void printAtLevelK(Tree *root, int k) {
    if (!root) return;

    if (k == 0) cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main() {
    Tree *root = takeInput();
    printTree(root);
    cout << "Total nodes : " << countNodes(root) << endl;
    cout << "Total leafs : " << countLeaf(root) << endl;
    cout << "Height      : " << height(root) << endl;
    int k;
    cout << "Enter level K : ";
    cin >> k;
    cout << "\nAt Level " << k << " : ";
    printAtLevelK(root, k);
    return 0;
}