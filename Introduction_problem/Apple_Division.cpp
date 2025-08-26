#include<iostream>
#include<vector>
#include<climits>
using ll = long long;

int main() {

    int n;
    std::cin >> n;
    std::vector<ll> arr(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        total += arr[i];
    }
    ll best=LLONG_MAX;

    for(int mask=0;mask<(1<<n);mask++)
    {
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))// since till n every possing combination can be created so pick that possible combination
            {
                sum+=arr[i];
            }
        }
        best = std::min(best, std::llabs(total - 2 * sum));
    }
    std::cout<<best<<"\n";
    return 0;
}