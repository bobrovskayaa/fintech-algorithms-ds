#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> answer;

void get_partition(int pos, int max, int n) {
    int i;
    if (!n) {
        for (i = 0; i < pos; i++)
            cout << answer[i] << ' ';
        cout << endl;
    } else
        for (i = 1; i <= min(max, n); i++) {
            answer[pos] = i;
            get_partition(pos+1, i, n-i);
    }
}

int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int n;
    cin >> n;
    answer.resize(n);
    get_partition(0, n, n);
    return 0;
}
