#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, target;
    cin >> n >> target;

    vector<pair<long long,int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;    
    }

    sort(arr.begin(), arr.end());

    unordered_map<long long, vector<pair<int,int>>> mp;
    mp.reserve(n * 4);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long s = arr[i].first + arr[j].first;
            mp[s].push_back({i, j});
        }
    }

    for(auto &entry : mp){
        long long s     = entry.first;
        long long need  = target - s;

        if(!mp.count(need)) continue;

        auto &v1 = entry.second;
        auto &v2 = mp[need];

        for(auto &p1 : v1){
            for(auto &p2 : v2){
                int a = p1.first,  b = p1.second;
                int c = p2.first,  d = p2.second;

                if(a!=c && a!=d && b!=c && b!=d){
                    cout << arr[a].second << " "
                         << arr[b].second << " "
                         << arr[c].second << " "
                         << arr[d].second;
                    return 0;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
