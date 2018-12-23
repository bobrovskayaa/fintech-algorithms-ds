#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    freopen("details.in", "r", stdin);
    freopen("details.out", "w", stdout);

    vector<int> time_for_detail;
    string line;
    getline(cin, line);
    istringstream is( line );
    int current_item;
    int N = 0;
    while( is >> current_item ) {
        time_for_detail.push_back(current_item);
        N++;
    }

    vector<vector<int>> adjacency_list(N, vector<int>());
    for (int j = 0; j < N; j++){
        getline(cin, line);
        istringstream is(line);
        while( is >> current_item ) {
            adjacency_list[j].push_back(current_item - 1);
        }
    }

    long long final_time = 0;
    bool *is_done;
    is_done = new bool[N];
    for (int k = 0; k < N; k++)
        is_done[k] = false;

    stack<int> details_to_do;
    details_to_do.push(0);
    while (!details_to_do.empty()){
        int temp_detail = details_to_do.top();
        details_to_do.pop();
        if (!is_done[temp_detail]) {
            final_time += time_for_detail[temp_detail];
            is_done[temp_detail] = true;
            for (const auto& p : adjacency_list[temp_detail]) {
                details_to_do.push(p);
            }
        }
    }
    cout << final_time;
    return 0;
}