#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    freopen("reverse.in", "r", stdin);
    freopen("reverse.out", "w", stdout);
    int n;
    string line;
    getline(cin, line);
    istringstream is(line);
    is >> n;
    vector<vector<int> > edges(n, vector<int>());
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream is(line);

        int number;
        while (is >> number) {
            edges[i].push_back(number - 1);
        }
    }
    cout << n << "\n";
    vector<vector<int>>G(n, vector<int>());
    for (int i = 0; i < n; i++) {
        auto size = edges[i].size();
        for (int j = 0; j < size; j++) {
            G[edges[i][j]].push_back(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}