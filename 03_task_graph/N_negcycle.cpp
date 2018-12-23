#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

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
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);

    int N;
    cin >> N;

    graph.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            cin >> w;
            if (w != 100000)
                graph[i].push_back(pil(j, w));
        }
    }

    bool flag = false;
    dist.resize(N);
    parent.resize(N);
    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
        parent[i] = -1;
    }

    int init = 0;
    dist[init] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < graph[j].size(); k++) {
                int v = graph[j][k].fi;
                if (dist[v] > dist[j] + graph[j][k].se) {
                    dist[v] = dist[j] + graph[j][k].se;
                    parent[v] = j;
                }
            }

    int i_bad = -1;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < graph[j].size(); k++) {
            int v = graph[j][k].fi;
            if (dist[v] > dist[j] + graph[j][k].se) {
                dist[v] = dist[j] + graph[j][k].se;
                parent[v] = j;
                flag = true;
                i_bad = v;
                break;
            }
        }
        if (flag) break;
    }

    if (flag) {
        cout << "YES" << endl;

        vector<int> answer;
        answer.resize(0);
        answer.push_back(i_bad);

        int cur = parent[i_bad];
        bool flag2 = true;
        int i_begin = cur;

        while (flag2) {
            for (int i = 0; i < answer.size(); i++)
                if (cur == answer[i]) {
                    flag2 = false;
                    i_begin = i;
                }
            answer.push_back(cur);
            cur = parent[cur];
        }

        cout << answer.size() - i_begin - 1 << endl;
        for (int i = (int)answer.size() - 1; i > i_begin; i--)
            cout << answer[i] + 1 << " ";
    }
    else
        cout << "NO" << endl;
    return 0;
}