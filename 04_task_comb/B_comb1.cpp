#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> answer;

void binary(int n, int k)
{
    static string prefix;
    if (n < k)
        return;
    if (n == 0) {
        answer.push_back(prefix);
        return;
    }

    prefix.push_back('0');
    binary(n-1,k);
    prefix.pop_back();
    if (k >= 1)
    {
        prefix.push_back('1');
        binary(n-1,k-1);
        prefix.pop_back();
    }
}

int main() {
    freopen("comb1.in", "r", stdin);
    freopen("comb1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    binary(n, m);
    for(const auto &s: answer) {
        for(auto c: s) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}