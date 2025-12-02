#include<iostream>
#include<vector>
const int mod=1e9+7;
int main()
{
    int l,sum;
    std::cin>>l>>sum;
    std::vector<int>coins(l);
    for(int i=0;i<l;i++)
    {
        std::cin>>coins[i];
    }
    std::vector<int>dp(sum+1,0);
    dp[0]=1;
    // Here order of coins doesn't matter so every coin will be checked
    for(int i=1;i<=sum;i++)
    {
        for(auto&it:coins)
        {
            if(i>=it)
            {
                dp[i]=(dp[i]+dp[i-it])%mod;
            }
        }
    }
    std::cout<<dp[sum];
    return 0;
}