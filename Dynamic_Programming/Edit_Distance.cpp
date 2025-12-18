#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// METHOD -1 Recursion
/*
std::string a, b;
int n, m;
std::vector<std::vector<int>> dp;

int solve(int i, int j) {
    if (i == n) return m - j;
    if (j == m) return n - i;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) {
        return dp[i][j] = solve(i + 1, j + 1);
    }

    int del = solve(i + 1, j);     
    int add = solve(i, j + 1);     
    int rep = solve(i + 1, j + 1); 

    return dp[i][j] = 1 + std::min({del, add, rep});
}

int main() {
    std::cin >> a >> b;
    n = a.size();
    m = b.size();

    dp.assign(n, std::vector<int>(m, -1));

    std::cout << solve(0, 0);
    return 0;
}
*/


// METHOD-2 OPTIMIZED DP

int main()
{
    std::string a,b;
    std::cin>>a>>b;
    int n=a.size(),m=b.size();

    std::vector<int>prev(m+1),curr(m+1);
    for(int i=0;i<=m;i++)
    {
        prev[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                curr[j]=prev[j-1];
            }
            else{
                // del=> previous value of string b to match it with a
                // add=> add value to the current going
                // replace=> matching it previous 
                curr[j]=1+std::min({
                    prev[j],
                    curr[j-1],
                    prev[j-1]
                });
            }
        }
        prev=curr;
    }
    std::cout<<prev[m];
    return 0;
}