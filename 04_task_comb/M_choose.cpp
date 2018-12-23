#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long factorial(long long n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long long get_num_choose(int n, int k) {
    if ( k < n-k ) {
        long long numerator = 1;
        for (int i=0; i < k; i++)
            numerator *= (n-i);
        return numerator / factorial(k);
    }  else {
        long long numerator = 1;
        int counter = 0;
        while (n - counter != k) {
            numerator *= (n - counter);
            ++counter;
        }
        return numerator / factorial(n-k);
    }
}

vector<int> get_choose(int n, int k, long long m) {
    int cur_number = 1;
    vector<int> answer;
    while (k > 0) {
        long long num_choose = get_num_choose(n-1, k-1);
        if (m < num_choose) {
            answer.push_back(cur_number);
            --k;
        } else {
            m -= num_choose;
        }
        --n;
        ++cur_number;
    }
    return answer;
}

int main()
{
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    int n, k;
    long long m;
    cin >> n >> k >> m;
    vector<int> a = get_choose(n, k, m);
    for (int i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}