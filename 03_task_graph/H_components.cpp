#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);

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

    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {
            order.push(i);
            parent[i] = -2;
            while (!order.empty()) {
                int current_vertex = order.front();
                order.pop();
                for (const auto &neib_vertex : vertices[current_vertex]) {
                    if (parent[neib_vertex] == -1) {
                        parent[neib_vertex] = current_vertex;
                        order.push(neib_vertex);
                    }
                }
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (parent[i] == -2) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}