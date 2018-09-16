#include <iostream>

using namespace std;

typedef long long int lli;

void quickSort(lli *arr, int N) {
    int from = 0, to = N - 1;
    lli current = arr[N / 2];

    while (from <= to) {
        while (arr[from] < current) from++;
        while (arr[to] > current) to--;

        if (from <= to) {
            lli temp = arr[from];
            arr[from] = arr[to];
            arr[to] = temp;
            from++;
            to--;
        }
    }

    if (to > 0) quickSort(arr, to);
    if (from < N - 1) quickSort(arr + from, N - from);
}

int main() {
    int N;
    cin >> N;
    auto arr = new lli[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    quickSort(arr, N);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
}