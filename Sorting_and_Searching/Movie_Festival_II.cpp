#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using ll=long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n,k;
    std::cin>>n>>k;
    /*
        The priority will fail as it would give only the top value and in case the 
        the latest one end is greater than start of curr it would reject it but there might come a case
        where one of the member get the free and eligible for the curr movie but due to the top showing issue of priority queue it would
        miss it
    */
    std::vector<std::pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i].first>>arr[i].second;
    }
    std::sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
        return a.second<b.second;
    });
    std::multiset<ll>mt;
    ll ans=0;
    for(auto &it:arr)
    {
        ll s=it.first,e=it.second;
        // is there exist a movie with ending time greater that curr start 
        auto curr=mt.upper_bound(s);
        if(curr!=mt.begin())// if curr == mt.begin() meaning all element after that would not be free
        {
            curr--;// points to last pointer thats actually in the set
            mt.erase(curr);
            mt.insert(e);
            ans++;
        }
        else if(mt.size()<k){
            mt.insert(e);
            ans++;
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}