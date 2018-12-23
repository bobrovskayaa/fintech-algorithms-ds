#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    int N;
    cin >> N;
    vector<vector<int>> vertices(N, vector<int>());
    vector<int> parent(N);
    queue<int> order;

    for (int i = 0; i <  N; i++) {
        for (int j = 0; j < N; j++) {
            int cur;
            cin >> cur;
            if (cur == 1) {
                vertices[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }

    order.push(0);
    parent[0] = -2;
    while (!order.empty()) {
        int current_vertex = order.front();
        order.pop();

        for (const auto& neib_vertex : vertices[current_vertex]) {
            if (parent[neib_vertex] != -1 && parent[current_vertex] != neib_vertex){
                cout << "NO";
                return 0;
            }
            if (parent[neib_vertex] == -1) {
                parent[neib_vertex] = current_vertex;
                order.push(neib_vertex);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}