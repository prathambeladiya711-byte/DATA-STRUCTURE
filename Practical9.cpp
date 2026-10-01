#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS Traversal
void DFS(int vertex) {
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// BFS Traversal
void BFS(int start) {
    queue<int> q;

    // Reset visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\nEnter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    // DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(start);

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;

    return 0;
}
