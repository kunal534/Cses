#include<iostream>
#include<vector>
#include<unordered_map>
int main()
{
    int n;
    std::cin>>n;
    std::vector<long long>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::unordered_map<long long,int>mp;
    long long ans=0,l=0;
    // sliding window
    for(int r=0;r<n;r++)
    {
        mp[arr[r]]++;
        while(mp[arr[r]]>1)
        {
            mp[arr[l]]--;
            l++;
        }
        ans+=(r-l+1);
    }
    std::cout<<ans<<"\n";
}