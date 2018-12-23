#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int main() {
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);

    int N;
    cin >> N;

    graph.resize(N);
    for (int i = 0; i < N; i++) {
        graph[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}