#include<iostream>
#include<vector>
#include<unordered_map>
int main()
{
    int a,b;
    std::cin>>a>>b;
    std::vector<long long>arr(a);
    for(int i=0;i<a;i++)
    {
        std::cin>>arr[i];
    }
    std::unordered_map<long long,long long>mp;
    mp[0]=1;
    long long curr=0, ans=0;
    for(int i=0;i<a;i++)
    {
        curr+=arr[i];
        if(mp.count(curr-b))ans+=mp[curr-b];
        mp[curr]++;
    }
    std::cout<<ans;
    return 0;
}