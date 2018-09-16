#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef long long int lli;
struct lastPair {
    lli a, b;
};

lastPair getTwoLast(stack<lli> &postfix) {
    lli a = postfix.top();
    postfix.pop();
    lli b = postfix.top();
    postfix.pop();
    return {a, b};
}

int main() {
    stack<lli> postfix;
    // string symbols = "8 9 + 1 7 - *";
    string symbols;
    getline(cin, symbols);
    for (char symbol : symbols) {
        switch (symbol) {
            case ' ':
                break;
            case '+': {
                lastPair pair = getTwoLast(postfix);
                postfix.push(pair.b + pair.a);
                break;
            }
            case '-': {
                lastPair pair = getTwoLast(postfix);
                postfix.push(pair.b - pair.a);
                break;
            }
            case '*': {
                lastPair pair = getTwoLast(postfix);
                postfix.push(pair.b * pair.a);
                break;
            }
            default:
                postfix.push(symbol - '0');
        }
    }
    cout << postfix.top();
    return 0;
}