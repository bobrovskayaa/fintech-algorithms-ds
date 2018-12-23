#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> get_prev(vector<int> a, vector<int> init) {
    int size = a.size();
    // find number greater than previous
    int previous = a[size-1];
    int marked1 = -1;
    for (int i = size - 2; i >= 0; i--) {
        if (a[i] > previous) {
            marked1 = i;
            break;
        }
        previous = a[i];
    }
    if (marked1 == -1)
        return init;

    // find number less than marked1
    int marked2 = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (a[i] < a[marked1]) {
            marked2 = i;
            break;
        }
    }

    // swap & sort
    iter_swap(a.begin() + marked1, a.begin() + marked2);
    sort(a.begin()+marked1+1, a.end(), greater<int>());
    return a;
}

int main()
{
    freopen("prev.in", "r", stdin);
    freopen("prev.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a.push_back(elem);
    }

    vector<int> init(n);
    iota(init.begin(), init.end(), 1);
    reverse(init.begin(), init.end());

    vector<int> next = get_prev(a, init);

    for (int i = 0; i < next.size(); i++)
        cout << next[i] << " ";
    cout << endl;
    return 0;
}