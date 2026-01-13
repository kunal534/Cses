#include <iostream>
#include <vector>

static const int mod = 1e9 + 7;
int main()
{
    int n;
    std::cin >> n;

    long long total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        std::cout << 0;
        return 0;
    }

    long long target = total / 2;
    std::vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (long long j = 1; j <= n; j++) {
        for (long long i = target; i >= j; i--) {
            dp[i] =(dp[i]+ dp[i - j])%mod;
        }
    }
    /*
        the dp stores the modified modulo answer not the correct one so we will need to first multiply it by mod
        but if directly multiplied by mod overflow can come and we also need the /2 value so as to remove the duplicates
        so inv2 [ inverse of 2 is used ] 
    */
    // modular inverse 
    long long inv2 = (mod+ 1) / 2;
    // inv2 is multipled resulting in correct answer and then mod is did
    std::cout << (dp[target] * inv2)%mod;
    return 0;
}
