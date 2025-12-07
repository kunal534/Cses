#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n,money;
    std::cin>>n>>money;
    std::vector<int>price(n,0),number(n,0);
    for(int i=0;i<n;i++)
    {
        std::cin>>price[i];
    }
    for(int i=0;i<n;i++)
    {
        std::cin>>number[i];
    }

    std::vector<int>dp(money+1,0);

    for(int i=0;i<n;i++)// index of arrys
    {
        for(int cost=money;cost>=price[i];cost--)// dp index
        {
            dp[cost]=std::max(dp[cost],number[i]+dp[cost-price[i]]);
        }
    }
    std::cout<<dp[money]<<"\n";
    return 0;
}