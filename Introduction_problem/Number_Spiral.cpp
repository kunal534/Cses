#include <iostream>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;
        long long n = max(y, x);
        long long ans;
        if (n % 2 == 0) {
            if (x == n)
                ans = n * n - (y - 1);
            else
                ans = (n - 1) * (n - 1) + x;
        } else {
            if (y == n)
                ans = n * n - (x - 1);
            else
                ans = (n - 1) * (n - 1) + y;
        }
        cout << ans << "\n";
    }
    return 0;
}