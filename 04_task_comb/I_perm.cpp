#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a.push_back(elem);
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    int remaining_pos = n - 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int f = factorial(remaining_pos);
        // find lexical order for a[i]
        auto lower = lower_bound(order.begin(), order.end(), a[i]);
        auto idx = lower - order.begin();
        sum += idx * f;
        order.erase(order.begin() + idx);
        --remaining_pos;
    }
    cout << sum+1;
    return 0;
}
