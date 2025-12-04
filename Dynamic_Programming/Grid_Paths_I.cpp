#include<iostream>
#include<vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<char>>arr(n,std::vector<char>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>arr[i][j];
        }
    }
    const int mod=1e9+7;
    std::vector<int>dp(n,0);

    if(arr[0][0]!='*')dp[0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]=='*')
            {
                dp[j]=0;
                continue;
            }
            if(j>0)
            {
                dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
    }
    std::cout<<dp[n-1]<<"\n";
    return 0;
}