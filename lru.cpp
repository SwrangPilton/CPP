#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    int value;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
    }
};

struct LRUCache      {
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
    }

    int insertKeyValue(string key, int value) {
        if (m.count(key) != 0) {
            auto it = m[key];
            it->value = value;
        } else {
            if (l.size() == maxSize) {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }
            Node n(key, value);
            l.push_front(n);
            m[key] = l.begin();
        }
        return 0;
    }

    int* getValue(string key) {
        if (m.count(key) != 0) {
            auto it = m[key];
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->value;
        }
        return NULL;
    }

    string getMostRecentKey() {
        return l.front().key;
    }
};

int main() {
    LRUCache l(4);
    l.insertKeyValue("Mango", 1);
    l.insertKeyValue("Apple", 2);
    l.insertKeyValue("Pineapple", 3);
    l.insertKeyValue("Guava", 4);
    int* value = l.getValue("Apple");
    cout << value << endl;
    string key = l.getMostRecentKey();
    cout << key << endl;
    return 0;
}