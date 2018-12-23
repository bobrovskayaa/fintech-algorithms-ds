#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

string get_next_brackets(string s) {
    int n = s.length();
    string answer;
    int checker_r = 0;
    int checker_s = 0;
    stack<char> br;
    for (int i = n-1; i >= 0; --i) {
        switch (s[i]) {
            case '(' : { checker_r--; br.pop(); break;}
            case ')': { checker_r++; br.push(')'); break;}
            case '[': { checker_s--; br.pop(); break;}
            case ']': { checker_s++; br.push(']'); break;}
        }
        if (s[i] == '(') {
            answer = s.substr(0, i) + '[';

            int rest = n-1-i-checker_r-checker_s;
            int round_brackets =(rest) / 2;
            answer += string(round_brackets, '(') + string(round_brackets, ')') + ']';

            while (!br.empty()) {
                answer += br.top();
                br.pop();
            }
            break;
        }
        if (!br.empty()) {
            if (s[i] == '[' && br.top() == ')') {
                --checker_r;
                br.pop();
                answer = s.substr(0, i) + ')';

                int rest = n - 1 - i - checker_r - checker_s;
                int round_brackets = (rest) / 2;
                answer += string(round_brackets, '(') + string(round_brackets, ')');

                while (!br.empty()) {
                    answer += br.top();
                    br.pop();
                }
                break;
            }
            if (s[i] == '[' && br.top() == ']') {
                --checker_s;
                br.pop();
                answer = s.substr(0, i) + ']';

                int rest = n - 1 - i - checker_r - checker_s;
                int round_brackets = (rest) / 2;
                answer += string(round_brackets, '(') + string(round_brackets, ')');

                while (!br.empty()) {
                    answer += br.top();
                    br.pop();
                }
                break;
            }
        }
    }
    return answer;
}

int main() {
    freopen("brackets2.in", "r", stdin);
    freopen("brackets2.out", "w", stdout);
    int n;
    cin >> n;
    if (n%2)
        return 0;
    string str = string(n/2 , '(') + string(n/2, ')');
    while (str.length()) {
        cout << str << endl;
        str = get_next_brackets(str);
    }
    return 0;
}