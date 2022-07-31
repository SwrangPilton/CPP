#include <bits/stdc++.h>
using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int data) : data(data), left(NULL), right(NULL) {}
};

void printTree(BTNode* root) {
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
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
BTNode* takeInput() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    BTNode* root = new BTNode(rootData);
    queue<BTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BTNode* f = q.front();
        q.pop();

        int leftChildData;
        cout << "Enter left data of " << f->data << " : ";
        cin >> leftChildData;

        if (leftChildData != -1) {
            BTNode* left = new BTNode(leftChildData);
            q.push(left);
            f->left = left;
        }

        int rightChildData;
        cout << "Enter right data of " << f->data << " : ";
        cin >> rightChildData;

        if (rightChildData != -1) {
            BTNode* right = new BTNode(rightChildData);
            q.push(right);
            f->right = right;
        }
    }
    return root;
}

BTNode* printInvert(BTNode* root) {
    if (!root) return NULL;
    swap(root->left, root->right);
    root->left = printInvert(root->left);
    root->right = printInvert(root->right);
    return root;
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
//! NEAREST LEAF NODE
struct qItem {
    BTNode* root;
    int depth;
};

int minDepth(BTNode* root) {
    if (!root) return 0;
    queue<qItem> q;
    qItem qi = {root, 1};
    q.push(qi);
    while (!q.empty()) {
        qItem f = q.front();
        q.pop();

        BTNode* root = f.root;
        int depth = f.depth;

        if (!root->left && !root->right) return depth;

        if (root->left) {
            qItem a = {root->left, depth + 1};
            q.push(a);
        }
        if (root->right) {
            qItem a = {root->right, depth + 1};
            q.push(a);
        }
    }
    return 0;
}

int countNodes(BTNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    return countNodes(root->left) +
           countNodes(root->right) + 1;
}

int countLeaf(BTNode* root) {
    if (!root) return 0;

    int count = 0;
    if (!root->left && !root->right) return 1;
    int left = countLeaf(root->left);
    int right = countLeaf(root->right);
    return left + right;
}

void inOrderTraversal(BTNode* root) {
    if (!root) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void inOrderTraversal(BTNode* root, vector<int>& inOrder) {
    if (!root) return;

    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->data);
    inOrderTraversal(root->right, inOrder);
}

void preOrderTraversal(BTNode* root) {
    if (!root) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void preOrderTraversal(BTNode* root, vector<int>& preOrder) {
    if (!root) return;

    preOrder.push_back(root->data);
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}

void postOrderTraversal(BTNode* root) {
    if (!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int minNode(BTNode* root) {
    if (!root)
        return INT_MAX;
    int leftMin = minNode(root->left);
    int rightMin = minNode(root->right);

    return min(root->data, min(leftMin, rightMin));
}

int maxNode(BTNode* root) {
    if (!root) return INT_MIN;
    int left = maxNode(root->left);
    int right = maxNode(root->right);
    return max(root->data, max(left, right));
}

bool hasNode(BTNode* root, int data) {
    if (!root) return false;

    if (root->data == data) return true;

    return hasNode(root->left, data) ||
           hasNode(root->right, data);
}

int maxDepth(BTNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

bool helper(BTNode* l, BTNode* r) {
    if (l == NULL && r != NULL) return false;
    if (l != NULL && r == NULL) return false;
    if (l == NULL && r == NULL) return true;
    if (l->data != r->data) return false;

    return helper(l->left, r->right) && helper(l->right, r->left);
}

bool isSymmetric(BTNode* root) {
    if (!root) return false;

    return helper(root->left, root->right);
}

BTNode* buildTreeHelper(vector<int> inOrder, vector<int> preOrder, int inS, int inE, int preS, int preE) {
    if (inS > inE) return NULL;

    int rootData = preOrder[preS];

    int leftInS = 0;
    int rootIdx = -1;
    for (int i = inS; i <= inE; i++) {
        if (inOrder[i] == rootData) {
            rootIdx = i;
            break;
        }
    }
    int leftInE = rootIdx - 1;
    int rightInS = rootIdx + 1;
    int rightInE = inE;

    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BTNode* root = new BTNode(rootData);
    root->left = buildTreeHelper(inOrder, preOrder, leftInS, leftInE, leftPreS, leftPreE);
    root->right = buildTreeHelper(inOrder, preOrder, rightInS, rightInE, rightPreS, rightPreE);
    return root;
}

BTNode* buildTree(vector<int>& inOrder, vector<int>& preOrder) {
    int n = inOrder.size();
    return buildTreeHelper(inOrder, preOrder, 0, n - 1, 0, n - 1);
}

bool getPath(BTNode* root, int data, vector<int>& pathVector) {
    if (!root) return false;

    if (root->data == data) return true;
    pathVector.push_back(root->data);
    bool left = getPath(root->left, data, pathVector);
    bool right = getPath(root->right, data, pathVector);
    if (left || right) return true;
    pathVector.pop_back();
    return false;
}

vector<vector<int>> levelOrderPrint(BTNode* root) {
    vector<vector<int>> v;
    vector<int> temp;

    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        BTNode* f = q.front();
        q.pop();

        if (f == NULL) {
            v.push_back(temp);
            temp.clear();
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            temp.push_back(f->data);
            if (f->left) {
                q.push(f->left);
                // temp.push_back(f->left->data);
            }
            if (f->right) {
                q.push(f->right);
                // temp.push_back(f->right->data);
            }
        }
    }
    return v;
}

vector<vector<int>> bottomUplevelOrderPrint(BTNode* root) {
    vector<vector<int>> v;
    vector<int> temp;

    stack<BTNode*> s;
    s.push(root);
    s.push(NULL);

    while (!s.empty()) {
        BTNode* f = s.top();
        s.pop();

        if (f == NULL) {
            v.push_back(temp);
            temp.clear();
            if (!s.empty()) {
                s.push(NULL);
            }
        } else {
            temp.push_back(f->data);
            if (f->left) {
                s.push(f->left);
            }
            if (f->right) {
                s.push(f->right);
            }
        }
    }
    return v;
}

vector<vector<int>> bottomUplevelOrderPrint2(BTNode* root) {
    vector<vector<int>> v;
    vector<int> temp;

    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        BTNode* f = q.front();
        q.pop();

        if (f == NULL) {
            v.push_back(temp);
            temp.clear();
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            temp.push_back(f->data);
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    BTNode* root = takeInput();
    printTree(root);
    cout << "Min Depth : " << minDepth(root) << endl;
    // cout << "\nLevel Order Print : " << endl;
    // vector<vector<int>> v = levelOrderPrint(root);
    // for (auto x : v) {
    //     for (auto e : x) {
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "\nBOTTOM UP Level Order Print : " << endl;
    // vector<vector<int>> v2 = bottomUplevelOrderPrint2(root);
    // for (auto x : v2) {
    //     for (auto e : x) {
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "Invert Tree print : " << endl;
    // BTNode* invert = printInvert(root);
    // printTree(invert);
    // cout << endl;
    // levelOrderPrint(invert);

    // vector<int> pathVector;
    // if (getPath(root, 9, pathVector) == 1) {
    //     for (auto x : pathVector) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // } else {
    //     cout << "9 is not present in the Binary Tree" << endl;
    // }

    // isSymmetric(root) == 1 ? cout << "Symmetric\n" : cout << "NOPE\n";

    // cout << "Max depth : " << maxDepth(root) << endl;

    // cout << "Leaf nodes : " << countLeaf(root) << endl;

    // hasNode(root, 10) == 1 ? cout << "Found\n" : cout << "Not Found\n";

    // cout << "Max Node : ";
    // cout << maxNode(root);
    // cout << endl;
    // cout << "Min Node : ";
    // cout << minNode(root);

    // cout << "Total Nodes : " << countNodes(root) << endl;

    // vector<int> inOrder;
    // cout << "inOrderTraversal : ";
    // inOrderTraversal(root, inOrder);
    // for (auto x : inOrder) cout << x << " ";
    // cout << endl;
    // cout << "inOrderTraversal : ";
    // inOrderTraversal(root);

    // cout << endl;

    // vector<int> preOrder;
    // preOrderTraversal(root, preOrder);
    // cout << "preOrderTraversal : ";
    // for (auto x : preOrder) cout << x << " ";
    // cout << "\npreOrderTraversal : ";
    // preOrderTraversal(root);
    // cout << "\npostOrderTraversal : ";
    // postOrderTraversal(root);

    //! BUILD TREE FROM preOrder and inOrder
    // BTNode* newTree = buildTree(inOrder, preOrder);
    // printTree(newTree);
    return 0;
}

// 3 9 20 -1 -1 15 17 -1 -1 -1 -1