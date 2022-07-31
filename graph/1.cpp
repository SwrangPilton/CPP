#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    list<int> *l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool unidir = true) {
        l[i].push_back(j);
        if (unidir) {
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "--> ";
            for (auto x : l[i]) {
                cout << x << " ";
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

        for (auto x : l[node]) {
            if (!visited[x]) {
                dfshelper(x, visited);
            }
        }
    }

    void dfs(int src) {
        bool *visited = new bool[V]{0};
        dfshelper(src, visited);
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
    g.printAdjList();
    cout << "BFS : ";
    g.bfs(1);
    cout << "\nDFS : ";
    g.dfs(1);
    return 0;
}