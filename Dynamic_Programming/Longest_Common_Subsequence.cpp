#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<long long>a(n),b(m);
    for(int i=0;i<n;i++)std::cin>>a[i];
    for(int i=0;i<m;i++)std::cin>>b[i];

    std::vector<std::vector<long long>>dp(n+1,std::vector<long long>(m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    std::cout<<dp[n][m]<<"\n";

    std::vector<long long>ans;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }else
        {
            j--;
        }
    }
    std::reverse(ans.begin(),ans.end());
    for(int it:ans)
    {
        std::cout<<it<<" ";
    }
    return 0;
}