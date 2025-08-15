#include<iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;

    long long expectedSum = (n * (n + 1)) / 2;
    long long actualSum = 0;

    for(long long i = 0; i < n - 1; i++) {
        long long num;
        cin >> num;
        actualSum += num;
    }
    cout << expectedSum - actualSum << endl;
    return 0;
}