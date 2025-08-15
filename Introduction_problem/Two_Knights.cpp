#include <iostream>
using namespace std;

long long solve(long long x){
    return x*x*(x*x-1)/2 - 4*(x-1)*(x-2);
}
int main() {
    long long n;
    cin >>n;
    for(long long i=1;i<=n;i++){
        cout << solve(i) << endl;
    }
    return 0;
}