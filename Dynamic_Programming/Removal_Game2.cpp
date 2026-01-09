// the diff way in this we will simply find the positive diff of the player with respect to other then simply 

#include<iostream>
#include<algorithm>
#include<vector>
#include <numeric>  
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
            dp[l][r]=std::max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
        }
    }
    long long total=std::accumulate(arr.begin(),arr.end(),0LL);
    /*

    first + second = S
    first - second = diff
    first=(S+diff)/2
    */
    long long ans=(total+dp[0][n-1])/2;
    std::cout<<ans<<"\n";
    return 0;
}