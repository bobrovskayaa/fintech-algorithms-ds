#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const long long MAX = 1e10;

vector<vector<int>> graph;
vector<long long> dist;
vector<int> color;

int main() {
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);

    int N, S, F;
    cin >> N >> S >> F;

    color.resize(N);
    dist.resize(N);
    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
        color[i] = 0;
        graph.emplace_back(N);
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    dist[S-1] = 0;
    for (int i = 0; i < N; i++) {
        int i_min = -1;
        for (int j = 0; j < N; ++j)
            if ((i_min == -1 || dist[j] < dist[i_min]) && color[j] == 0)
                i_min = j;

        if (dist[i_min] == MAX)
            break;

        color[i_min] = 1;
        for (int u = 0; u < graph[i_min].size(); u++) {
            if (dist[u] > dist[i_min] + graph[i_min][u] && graph[i_min][u] != -1) {
                dist[u] = dist[i_min] + graph[i_min][u];
            }
        }
    }
    if (dist[F-1] < MAX) {
        cout << dist[F - 1];
    } else {
        cout << -1;
    }
    return 0;
}
