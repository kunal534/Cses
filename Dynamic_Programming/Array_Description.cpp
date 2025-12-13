#include<iostream>
#include<vector>
#include<cstring>
const int mod=1e9+7;
int n, m;
std::vector<int> a;
int dp[100001][101];
int solve(int index,int val)
{
    if(val<1 || val>m)return 0;
    if(a[index]!=0 && a[index]!=val)return 0;// as its not unknown
    if(index==n-1)return 1;
    if(dp[index][val]!=-1)return dp[index][val];

    int &curr=dp[index][val];
    curr=0;
    curr=(curr+solve(index+1,val-1))%mod;
    curr=(curr+solve(index+1,val))%mod;
    curr=(curr+solve(index+1,val+1))%mod;
    return curr;
}
// int main()
// {
//     std::cin>>n>>m;
//     a.resize(n);
//     for(int i=0;i<n;i++)std::cin>>a[i];

//     memset(dp,-1,sizeof(dp));
//     long long ans=0;
//     if(a[0]==0){
//         for(int i=1;i<=m;i++)
//         {
//             ans=(ans+solve(0,i))%mod;
//         }
//     }else{
//             ans=solve(0,a[0]);
//         }
//     std::cout<<ans<<"\n";
//     return 0;
// }

int main()
{
    std::cin>>n>>m;
    a.resize(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int>prev(m+2,0),curr(m+2,0);
    
    if(a[0]==0)
    {
        for(int i=1;i<=m;i++)prev[i]=1;
    }
    else{
        prev[a[0]]=1;
    }
    for(int i=1;i<n;i++)
    {
        fill(curr.begin(),curr.end(),0);
        if(a[i]==0)
        {
            for(int j=1;j<=m;j++)// try all
            {
                curr[j]=((long long)prev[j-1]+(long long)prev[j]+(long long)prev[j+1])%mod;
            }
        }else{
            int j=a[i];// go for it prev, curr, +1
            curr[j]=((long long)prev[j-1]+(long long)prev[j]+(long long)prev[j+1])%mod;
        }
        prev=curr;
    }
    int ans=0;
    for (int v = 1; v <= m; v++) ans = (ans + prev[v]) % mod;
    std::cout << ans << "\n";
    return 0;
}