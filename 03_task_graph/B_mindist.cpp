#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("mindist.in", "r", stdin);
    freopen("mindist.out", "w", stdout);
    int N, x;
    cin >> N;
    cin >> x;
    vector<vector<int>> vertices(N, vector<int>());
    vector<int> dist(N);
    queue<int> order;

    for (int i = 0; i <  N; i++) {
        for (int j = 0; j < N; j++) {
            int cur;
            cin >> cur;
            if (cur == 1) {
                vertices[i].push_back(j);
            }
        }
        dist[i] = -1;
    }
    order.push(x-1);
    dist[x-1] = 0;

    while (!order.empty()) {
        int current_index = order.front();
        order.pop();
        for (int j = 0; j < vertices[current_index].size(); j++) {
            int vertex = vertices[current_index][j];
            if (dist[vertex] == -1) {
                order.push(vertex);
                dist[vertex] = dist[current_index] + 1;
            }
        }
    }

    for (int i = 0; i <  N; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}