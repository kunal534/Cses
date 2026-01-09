#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::vector<std::vector<long long>>dp(n,std::vector<long long>(n,0));
    // the changing factor are l and r only and at last which is equal from left and right the last option would be selected 
    std::vector<long long>prefix(n+1,0);
    for(int i=0;i<n;i++)
    {
        prefix[i+1]=prefix[i]+arr[i];
    }

    auto sum=[&](int a,int b)
    {
        return prefix[b+1]-prefix[a];
    };

    // base case
    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i];
    }
    // changing length and traversing left to right
    for(int len=2;len<=n;len++)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r=l+len-1;
            long long temp=sum(l,r);
            dp[l][r]=std::max(temp-dp[l+1][r],temp-dp[l][r-1]);
        }
    }
    std::cout<<dp[0][n-1];
    return 0;
}