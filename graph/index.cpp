#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<int> *l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "--> ";
            for (auto nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int f = q.front();
            cout << f << " ";
            q.pop();

            for (auto nbr : l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfshelper(int node, bool *visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                dfshelper(nbr, visited);
            }
        }
    }

    void dfs(int source) {
        bool *visited = new bool[V]{0};
        dfshelper(source, visited);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);

    g.bfs(1);
    // cout << endl;
    // g.dfs(1);
    return 0;
}