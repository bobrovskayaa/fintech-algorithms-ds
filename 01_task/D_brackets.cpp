#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string brackets;
    getline(cin, brackets);
    stack<char> checker;
    for (char &c : brackets) {
        if ((c == '(') || (c == '{') || (c == '[')) checker.push(c);
        else if (((c == ')') && (checker.top() == '(')) ||
                 ((c == ']') && (checker.top() == '[')) ||
                 ((c == '}') && (checker.top() == '{')))
            checker.pop();
        else {
            cout << "NO";
            return 0;
        }
    };
    if (checker.empty()) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}