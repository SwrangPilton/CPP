#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node *takeInput() {
    int n;
    cout << "Enter data : ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    while (n != -1) {
        Node *newNode = new Node(n);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> n;
    }
    return head;
}

void printLinkedList(Node *node) {
    while (node) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void length(Node *node) {
    int cnt = 0;
    while (node) {
        cnt++;
        node = node->next;
    }
    cout << "Total Length : " << cnt << endl;
}

void printIthNode(Node *node, int i) {
    int cnt = 1;
    while (cnt < i && node) {
        cnt++;
        node = node->next;
    }

    if (node) cout << i << "th Node : " << node->data << endl;
}

Node *replaceIthNode(Node *node, int i, int data) {
    int cnt = 1;
    Node *temp = node;
    while (cnt < i && temp) {
        cnt++;
        temp = temp->next;
    }

    if (temp) temp->data = data;
    return node;
}

void deleteIthNode(Node *node, int i) {
    int cnt = 1;
    while (cnt < i - 1 && node) {
        cnt++;
        node = node->next;
    }
    node->next = node->next->next;
}

bool searchNode(Node *node, int data) {
    while (node) {
        if (node->data == data) return true;
        node = node->next;
    }
    return false;
}

void middleNode(Node *node) {
    Node *slow = node;
    Node *fast = node->next;

    while (fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element : ";

    if (fast == NULL)
        cout << slow->next->data << endl;
    else
        cout << slow->data << endl;
}

Node *removeKthNodeFromEnd(Node *node, int i = 2) {
    if (i == 0) return NULL;
    int cnt = 0;
    Node *temp = node;
    while (temp) {
        cnt++;
        temp = temp->next;
    }

    Node *curr = node;
    int jump = 1;
    while (jump <= cnt - i && curr) {
        jump++;
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return node;
}

Node *merge(Node *head1, Node *head2) {
    Node *finalHead = NULL;
    if (head1->data < head2->data) {
        finalHead = head1;
        head1 = head1->next;
    } else {
        finalHead = head2;
        head2 = head2->next;
    }

    Node *finalTail = finalHead;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            finalTail->next = head1;
            head1 = head1->next;
        } else {
            finalTail->next = head2;
            head2 = head2->next;
        }
        finalTail = finalTail->next;
    }

    if (head1) finalTail->next = head1;
    if (head2) finalTail->next = head2;

    return finalHead;
}

//! SORTLIST NOT FUNCTIONING
Node *sortList(Node *node) {
    Node *slow = node;
    Node *fast = node->next;

    while (node && node->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newNode = slow->next;
    slow->next = NULL;

    // while (node) {
    //     cout << node->data << " ";
    //     node = node->next;
    // }

    // while (newNode) {
    //     cout << newNode->data << " ";
    //     newNode = newNode->next;
    // }

    // cout << node->data << endl;
    // cout << newNode->data << endl;

    Node *a = sortList(node);
    Node *b = sortList(newNode);

    node = merge(a, b);
    return node;
    // cout << sortedList->data << endl;
    // while(sortedList){

    // }

    // return sortedList;
    // return NULL;
}

void maxNode(Node *node) {
    int max = INT_MIN;
    while (node) {
        if (node->data > max) {
            max = node->data;
        }
        node = node->next;
    }

    cout << "MAX NODE : " << max << endl;
}

void minNode(Node *node) {
    int min = INT_MAX;
    while (node) {
        if (node->data < min) {
            min = node->data;
        }
        node = node->next;
    }

    cout << "MIN NODE : " << min << endl;
}

Node *reverseNodes(Node *node) {
    Node *curr = node;
    Node *prev = NULL;

    while (curr) {
        Node *n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }

    while (prev) {
        cout << prev->data << "->";
        prev = prev->next;
    }
    cout << "NULL" << endl;
    return NULL;
    // return prev;
}

int main() {
    Node *head = takeInput();
    printLinkedList(head);
    reverseNodes(head);
    // printLinkedList(head);
    // maxNode(head);
    // minNode(head);
    // Node *sortedList = sortList(head);
    // printLinkedList(sortedList);

    // Node *head1 = takeInput();
    // printLinkedList(head1);

    // Node *head2 = takeInput();
    // printLinkedList(head2);

    // Node *mergedList = merge(head1, head2);
    // printLinkedList(mergedList);

    // removeKthNodeFromEnd(head, 0);
    // printLinkedList(head);

    // length(head);

    // middleNode(head);

    // searchNode(head, 3) == 1 ? cout << "Found\n" : cout << "Nope\n";

    // deleteIthNode(head, 3);
    // printLinkedList(head);

    // length(head);
    // replaceIthNode(head, 1, 100);
    // printLinkedList(head);
    return 0;
}