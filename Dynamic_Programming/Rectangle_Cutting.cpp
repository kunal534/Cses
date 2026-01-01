#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    // THIS ONE FAILS
    // int a,b;
    // std::cin>>a>>b;
    // int ans=0;
    // while(a!=b)
    // {
        //     if(a>b)a-=b;
        //     else b-=a;
        //     ans++;
    // }
    // std::cout<<ans;
    // return 0;
    int a,b;
    std::cin>>a>>b;
    std::vector<std::vector<int>>dp(a+1,std::vector<int>(b+1,1e9));

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==j)dp[i][j]=0;
            else 
            {
                // vertical cuts
                for(int k=1;k<i;k++)
                {
                    dp[i][j]=std::min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
                // horizontal cuts
                for(int k=1;k<j;k++)
                {
                    dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
    std::cout<<dp[a][b];
    return 0;
}