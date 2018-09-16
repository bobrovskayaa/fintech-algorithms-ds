#include <iostream>
#include <set>

using namespace std;

typedef set<int> si;
const int MAX_SCORE = 601;

int main() {
    int N;
    cin >> N;
    si arrOfSets[MAX_SCORE];
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;
        arrOfSets[score].insert(i);
    }
    for (int i = MAX_SCORE - 1; i >= 0; i--) {
        if (!arrOfSets[i].empty()) {
            for (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<int> > >::value_type it : arrOfSets[i]) {
                cout << it + 1 << ' ';
            }
        }
    }
    return 0;
}

