#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n; }

int main()
{
    freopen("bynumber.in", "r", stdin);
    freopen("bynumber.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> order(n);
    vector<int> answer;
    iota(order.begin(), order.end(), 1);
    int segment = k;
    int delimeter = n - 1;
    while (delimeter != 1) {
        int f = factorial(delimeter);
        int cur_number = segment / f;
        answer.push_back(order[cur_number]);
        order.erase(order.begin() + cur_number);
        segment = segment % f;
        delimeter = delimeter - 1;
    }
    if (segment == 1)
        reverse(std::begin(order), std::end(order));
    for (int i : order)
        answer.push_back(i);
    for (int i : answer)
        cout << i << ' ';
    return 0;
}