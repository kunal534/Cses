#include<iostream>
#include<vector>
#include<map>
#define ll long long
int main()
{
    ll a,target;
    std::cin>>a>>target;
    std::vector<ll>arr(a);
    for(ll i=0;i<a;i++)
    {
        std::cin>>arr[i];
    }
    ll ans=0,curr=0;
    std::map<long long,long long>mp;
    mp[0]=1;
    for(long long it:arr)
    {   
        curr+=it;
        if(mp.count(curr-target))ans+=mp[curr-target];
        mp[curr]++;
    }
    std::cout<<ans<<"\n";
    return 0;   
}