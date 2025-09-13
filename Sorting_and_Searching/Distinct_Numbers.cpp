#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n;
    cin >> n;
    /*
        The option with set failed due to internal collosion for veru high value of n
    */
    vector<long long> numbers(n);

    for(int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int distinct = 1; 
    for(int i = 1; i < n; ++i) {
        if(numbers[i] != numbers[i - 1]) {
            distinct++;
        }
    }

    cout << distinct << endl;
    return 0;
}
