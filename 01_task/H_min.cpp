#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    auto arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min_el_of_segm = arr[0];
    for (int i = 1; i < k; i++) {
        if (arr[i] < min_el_of_segm) min_el_of_segm = arr[i];
    }
    cout << min_el_of_segm << endl;

    int pointer = 1;
    while (pointer < n - k + 1) {
        if ((min_el_of_segm != arr[pointer - 1]) && (arr[pointer + k - 1] > min_el_of_segm)) {
            cout << min_el_of_segm << endl;
            pointer++;
        } else {
            min_el_of_segm = arr[pointer];
            for (int i = pointer; i < k + pointer; i++) {
                if (arr[i] < min_el_of_segm) min_el_of_segm = arr[i];
            }
            cout << min_el_of_segm << endl;
            pointer++;
        }
    }
    return 0;
}