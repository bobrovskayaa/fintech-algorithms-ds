#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> answer;

void fibseq(int n, int k)
{
    static string prefix;
    if (n == 0) {
        answer.push_back(prefix);
        return;
    }

    prefix.push_back('0');
    fibseq(n-1,k);
    prefix.pop_back();

    if (!prefix.empty() && prefix.back() == '1') {
        return;
    }

    prefix.push_back('1');
    fibseq(n - 1, k - 1);
    prefix.pop_back();
}

int main() {
    freopen("fibseq.in", "r", stdin);
    freopen("fibseq.out", "w", stdout);
    int n;
    cin >> n;
    fibseq(n, n);
    for(const auto &s: answer) {
        for(auto c: s) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}