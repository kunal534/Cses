#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using ll = long long;
int main(){
    ll l,target;
    std::cin>>l>>target;
    std::vector<ll>dp(target+1,LLONG_MAX);
    dp[0]=0;
    std::vector<ll>coins(l);
    for(ll i=0;i<l;i++)
    {
        std::cin>>coins[i];
    }
    for(ll i=1;i<=target;i++)
    {
        for(ll j=0;j<l;j++)
        {
            if(coins[j]>i || dp[i-coins[j]] == LLONG_MAX)  
            {
                continue;
            }
            dp[i]=std::min(dp[i],dp[i-coins[j]]+1);
        }
    }
    if(dp[target] == LLONG_MAX)std::cout<<-1<<"\n";
    else std::cout<<dp[target];
    return 0;
}