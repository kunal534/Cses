#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::pair<long long,long long>>arr(n,{0,0});
    for(int i=0;i<n;i++)
    {
        std::cin >> arr[i].first >> arr[i].second;
    }
    long long ans=0,time=0;
    std::sort(arr.begin(),arr.end(),[&](const auto& a, const auto &b){
        return a.first<b.first;
    });
    // shortest job first
    for(auto&it:arr)
    {
        time+=it.first;
        ans+=it.second-time;
    }
    std::cout<<ans<<"\n";
    return 0;
}