#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    
    sort(sticks.begin(), sticks.end());
    long long median = sticks[n/2];
    
    long long cost = 0;
    for (auto x : sticks) {
        cost += llabs(x - median);
    }
    
    cout << cost << "\n";
    return 0;
}
