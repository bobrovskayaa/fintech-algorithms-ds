#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("mindist2.in", "r", stdin);
    freopen("mindist2.out", "w", stdout);
    int N, m;
    cin >> N >> m;
    vector<vector<int>> vertices(N, vector<int>());
    vector<int> dist(N);
    vector<int> parent(N);
    queue<int> order;

    int begin, end;
    cin >> begin >> end;

    if (begin == end) {
        cout << 0 << endl;
        cout << begin;
        return 0;
    }

    for (int i = 0; i <  m; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a-1].push_back(b-1);
        vertices[b-1].push_back(a-1);
    }

    for (int i = 0; i < N; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }
    order.push(begin-1);
    dist[begin-1] = 0;

    while (!order.empty()) {
        int current_index = order.front();
        order.pop();
        for (int j = 0; j < vertices[current_index].size(); j++) {
            int vertex = vertices[current_index][j];
            if (dist[vertex] == -1) {
                order.push(vertex);
                parent[vertex] = current_index;
                dist[vertex] = dist[current_index] + 1;
            }
        }
    }

    if (dist[end-1] == -1) {
        cout << -1;
    } else {
        cout << dist[end-1] << endl;
        vector<int> path;
        int current_parent = parent[end - 1];
        while (dist[current_parent] != 0) {
            path.push_back(current_parent);
            current_parent = parent[current_parent];
        }
        path.push_back(current_parent);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] + 1 << " ";
        }
        cout << end;
    }
    return 0;
}