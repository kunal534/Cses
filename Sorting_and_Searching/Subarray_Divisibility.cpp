#include<iostream>
#include<map>
#include<vector>
#define ll long long 
int main()
{
    ll n;
    std::cin>>n;
    std::vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::map<ll,ll>mp;
    ll curr=0,ans=0;
    mp[0]=1;
    for(ll& it:arr)
    {
        /*
        The issue with this C++ keeps -ve sign so solve this issue
        ll left=curr%n;
        if(mp.count(left))ans++;
        mp[curr]++;

        */

        curr+=it;
        ll left=(curr%n+n)%n;// ensure non-negative number
        ans+=mp[left];
        mp[left]++;
    }
    std::cout<<ans<<"\n";
    return 0;
}