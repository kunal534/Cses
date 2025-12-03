#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        while(x)
        {
            int r=x%10;
            if(r>0){
                dp[i]=std::min(dp[i],dp[i-r]+1);// current vs current-rem +1(this step)
            }
            x=x/10;
        }
    }
    std::cout<<dp[n]<<"\n";
    return 0;
}