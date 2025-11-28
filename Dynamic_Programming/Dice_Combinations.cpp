#include<iostream>
#include<vector>
const int mod=1e9+7;
int main()
{
    int n;
    std::cin>>n;
    std::vector<long long>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int d=1;d<=6;d++)
        {
            if((i-d)>=0) dp[i]=(dp[i]+dp[i-d])%mod;
        }
    }
    std::cout<<dp[n];
    return 0;
}