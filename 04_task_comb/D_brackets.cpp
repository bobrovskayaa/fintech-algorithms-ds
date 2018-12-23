#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string get_next_brackets(string s) {
    int n = s.length();
    string answer;
    int checker = 0;
    for (int i = n-1; i >= 0; --i) {
        checker = s[i] == '(' ? checker-1 : checker+1;
        if (s[i] == '(' && checker > 0) {
            --checker;
            int rest = n-1-i;
            int open_brackets =(rest - checker) / 2;
            answer = s.substr(0,i) + ')' + string(open_brackets, '(') + string(rest - open_brackets, ')');
            break;
        }
    }
    return answer;
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int n;
    cin >> n;
    string str = string(n, '(') + string(n, ')');
    while (str.length()) {
        cout << str << endl;
        str = get_next_brackets(str);
    }
    return 0;
}