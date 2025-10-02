#include<iostream>
#include<vector>
#include<map>
#define ll long long
int main()
{
    ll n;
    std::cin>>n;
    std::vector<long long>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }

    ll start = 0, ans = 0;
    std::map<ll, ll> mp;
    /*
        cant go with unordered_map way as it failing in the case of hashing

    */
    for (ll end = 0; end < n; end++) {

        if (mp.find(arr[end]) == mp.end())
            mp.insert({ arr[end], end });
        else {
            if (mp[arr[end]] >= start)
                start = mp[arr[end]] + 1;            
            mp[arr[end]] = end;
        }
        ans = std::max(ans, end - start + 1);
    }
    std::cout<<ans;
    return 0;
}