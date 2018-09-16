#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> groups;
    int memory;
    int counter = 0;
    int n, k;
    cin >> n >> k;
    groups.push(n);
    while (!groups.empty()) {
        if (groups.top() > k) {
            memory = groups.top();
            groups.pop();
            groups.push(memory / 2);
            groups.push(memory - memory / 2);
        } else {
            counter++;
            groups.pop();
        }
    }
    cout << counter;
    return 0;
}