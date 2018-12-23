#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> vertices;
vector<int> answer;
vector<int> color;
bool isCycle = false;

void dfs(int v) {
    color[v] = 1;
    for (int neib_vertex: vertices[v]) {
        if (color[neib_vertex] == 1) {
            isCycle = true;
        }
        if (color[neib_vertex] == 0) {
            dfs(neib_vertex);
        }
    }
    answer.push_back(v);
    color[v] = 2;
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    color.resize(N);
    for (int i = 0; i < N; i++) {
        color[i] = 0;
        vertices.emplace_back();
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a-1].push_back(b-1);
    }

    for (int i = 0; i < N; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
        if (isCycle) {
            cout << -1;
            return 0;
        }
    }
    reverse(answer.begin(), answer.end());

    for (int vertex : answer) {
        cout << vertex + 1 << " ";
    }
    return 0;
}