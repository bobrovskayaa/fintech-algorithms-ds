#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> vertices(N, vector<int>());
    vector<int> part(N);
    vector<int> parent(N);
    queue<int> order;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a-1].push_back(b-1);
        vertices[b-1].push_back(a-1);
    }

    for (int i = 0; i < N; i++) {
        part[i] = -1;
        parent[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        if (part[i] == -1) {
            order.push(i);
            part[i] = 0;
            while (!order.empty()) {
                int current_vertex = order.front();
                order.pop();
                for (const auto& neib_vertex : vertices[current_vertex]) {
                    if (part[neib_vertex] == -1) {
                        parent[neib_vertex] = current_vertex;
                        part[neib_vertex] = (part[current_vertex] + 1) % 2;
                        order.push(neib_vertex);
                    } else {
                        if (part[current_vertex] == part[neib_vertex]) {
                            cout << "NO";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "YES";
    return 0;
}