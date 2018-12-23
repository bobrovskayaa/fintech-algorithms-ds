#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> get_next(vector<int> a, int n) {
    int size = a.size();
    for (int i = size-1; i >=0; i--) {
        int cur_biggest = n-(size-1-i);
        if (a[i] != cur_biggest) {
            a[i] += 1;
            for (int j = i+1; j < size; j++) {
                a[j] = a[i] + (j-i);
            }
            break;
        }
    }
    return a;
}

int main()
{
    freopen("nextcomb.in", "r", stdin);
    freopen("nextcomb.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < k; i++) {
        int elem;
        cin >> elem;
        a.push_back(elem);
    }
    vector<int> next = get_next(a, n);

    if (next == a) {
        cout << 0;
        return 0;
    }
    for (int i : next)
        cout << i << " ";
    cout << endl;
    return 0;
}