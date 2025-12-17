/*
 Note the question never mentioned both tower need to of same height in the end
*/

#include<iostream>
#include<vector>
static const long long mod=1e9+7;
static const long long m=1e6;
int main(){
    int t;
    std::cin>>t;
    std::vector<long long>dp0(m+1),dp1(m+1);
    dp0[1]=1;
    dp1[1]=1;

    for(int i=2;i<=m;i++)
    {
        dp0[i]=(2*dp0[i-1] + dp1[i-1])%mod;//for col0 we can chose either 2 (1x1) or 1 (2x1) and for col1 use pervious
        dp1[i]=(dp0[i-1]+ 4*dp1[i-1])%mod;//  increase shorter + increase taller + extend both unevely + reverse of previous
    }
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << (dp0[n] + dp1[n]) % mod << "\n";
    }
    return 0;
}