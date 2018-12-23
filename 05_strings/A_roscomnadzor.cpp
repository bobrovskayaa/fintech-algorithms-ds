#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
    return z;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string little;
    string big_init;
    string current;

    getline(cin, little);
    getline(cin, big_init);
    while(getline(cin, current))
        big_init += '\n' + current;

    string big = big_init;
    std::replace( big.begin(), big.end(), '\n', ' ');

    string merged = little + '#' + big;
    std::transform(merged.begin(), merged.end(), merged.begin(), ::tolower);

    vector<int> calculated = z_function(merged);
    int little_size = little.length();

    int current_begin = -1;
    for (int i = 0; i < calculated.size(); i++) {
        if (calculated[i] == little_size) {
            current_begin = i;
        }
        if (i > little_size && i < current_begin + little_size) {
            char current_value = big_init[i - little_size - 1];
            if (!(current_value == ' ' || current_value == '\n'))
                big_init.replace(i - little_size - 1, 1, "*");
        }
    }
    cout << big_init;

    return 0;
}
