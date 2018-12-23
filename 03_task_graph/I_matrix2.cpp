#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("matrix2.in", "r", stdin);
    freopen("matrix2.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> vertices(N, vector<int>());
    vector<int> parent(N);
    queue<int> order;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a-1].push_back(b-1);
        vertices[b-1].push_back(a-1);
    }

    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }

    int counter = 0;
    vector<vector<int>> components;
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {
            vector<int> current_component;
            counter++;
            order.push(i);
            parent[i] = -2;
            while (!order.empty()) {
                int current_vertex = order.front();
                current_component.push_back(current_vertex);
                order.pop();
                for (const auto &neib_vertex : vertices[current_vertex]) {
                    if (parent[neib_vertex] == -1) {
                        parent[neib_vertex] = current_vertex;
                        order.push(neib_vertex);
                    }
                }
            }
            components.push_back(current_component);
        }
    }
    cout << counter << endl;
    for (const auto &component : components) {
        cout << component.size() << endl;
            for (const auto &vertex : component) {
                cout << vertex + 1 << " ";
            }
        cout << endl;
    }
    return 0;
}