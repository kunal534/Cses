#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long count=0;
    for(long long it=5;it<=n;it*=5){
        count+=n/it;
    }
    cout<<count<<endl;
    return 0;
}