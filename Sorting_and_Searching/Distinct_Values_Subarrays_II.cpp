#include<iostream>
#include<vector>
#include<map>
#define ll long long
int main()
{
    int a,b;
    std::cin>>a>>b;
    std::vector<ll>arr(a);
    for(ll i=0;i<a;i++)
    {
        std::cin>>arr[i];
    }
    std::map<ll,ll>mp;
    ll ans=0;
    ll left=0;
    for(ll right=0;right<a;right++)
    {
        mp[arr[right]]++;
        while(mp.size()>b)
        {
            mp[arr[left]]--;
            if(mp[arr[left]]==0)mp.erase(arr[left]);
            left++;
        }
        ans+=(right-left+1);
    }
    std::cout<<ans<<"\n";
    return 0;
}