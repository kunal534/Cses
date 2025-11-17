#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;

    vector<pair<long long,int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;       
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        long long target = x - arr[i].first;
        int l = i + 1, r = n - 1;

        while(l < r){
            long long sum = arr[l].first + arr[r].first;
            if(sum == target){
                cout << arr[i].second << " "
                     << arr[l].second << " "
                     << arr[r].second << "\n";
                return 0;
            }
            if(sum < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
