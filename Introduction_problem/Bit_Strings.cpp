#include<iostream>
using namespace std;

int main(){
    const int mod=1e9+7;
    int n;
    cin>>n;
    long long ans=1;
    long long base=2;
    while(n>0){
        if(n&1){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        n>>=1;
    }   
    cout<<ans<<endl;
    return 0;
}