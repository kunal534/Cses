#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp; 
    long long ans = 0;
    int right = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(arr[i])) {
            right = min(right, mp[arr[i]] - 1);
        }

        ans += (right - i + 1);
        mp[arr[i]] = i;
    }

    cout << ans << "\n";
    return 0;

}
