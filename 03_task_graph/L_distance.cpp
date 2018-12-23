#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

#define fi first
#define se second
#define pil pair<int, long long>

const int MAX = 1e9;

vector<vector<pil>> graph;
vector<long long> dist;
vector<int> parent;
vector<int> color;

int main() {
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);

    int N, M, S, F;
    cin >> N >> M >> S >> F;

    graph.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a-1].emplace_back(pil(b-1, w));
        graph[b-1].emplace_back(pil(a-1, w));
    }

    dist.resize(N);
    parent.resize(N);
    color.resize(N);
    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
        parent[i] = -1;
        color[i] = 0;
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
        for (int k = 0; k < graph[i_min].size(); k++)
            if (dist[graph[i_min][k].fi] > dist[i_min] + graph[i_min][k].se) {
                dist[graph[i_min][k].fi] = dist[i_min] + graph[i_min][k].se;
                parent[graph[i_min][k].fi] = i_min;
            }
    }

    if (dist[F-1] == MAX) {
        cout << -1;
    } else {
        cout << dist[F - 1] << endl;

        vector<int> answer;
        int current_vertex = F-1;
        while (current_vertex != -1) {
            answer.push_back(current_vertex);
            current_vertex = parent[current_vertex];
        }
        for (int i = answer.size() - 1; i >= 0; i--)
            cout << answer[i] + 1 << " ";
    }
    return 0;
}