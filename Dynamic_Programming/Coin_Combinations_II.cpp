#include<iostream>
#include<vector>
const int mod = 1e9+7;

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;
    // Unique set so we don't need to check all ways a certain sum can be made instead we will check the number one coin can make
    for(int it:coins)
    {
        for(int i=it;i<=x;i++)
        {
            dp[i]=(dp[i]+dp[i-it])%mod;
        }
    }
    std::cout << dp[x] << "\n";
    return 0;
}
