#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <deque>

using namespace std;

void binary(int n, int k)
{
    static deque<string> prefix;
    if (n == 0) {
        for (deque<string> dump = prefix; !dump.empty(); dump.pop_front())
            cout << dump.front() << ' ';
        cout << endl;
        return;
    }

    for (int i = n; i <= k; i++) {
        string s = to_string(i);
        prefix.push_back(s);
        binary(n-1, i-1);
        prefix.pop_back();
    }
}

int main() {
    freopen("comb2.in", "r", stdin);
    freopen("comb2.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    binary(n, k);
    return 0;
}