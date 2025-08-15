#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sum=n*(1+n)/2;
    if(sum%2!=0){
        cout<<"NO"<<endl;
    }else{
        long long target=sum>>1;
        vector<int> set1,set2;
        for(long long i=n;i>=1;i--){
            if(target>=i){
                set1.push_back((int)i);
                target-=i;
            }else{
                set2.push_back((int)i);
            }
        }
        cout<<"YES"<<endl;
        reverse(set1.begin(),set1.end());
        reverse(set2.begin(),set2.end());
        cout<<set1.size()<<endl;
        for(auto it:set1){
            cout<<it<<" ";
        }
        cout << '\n';
        cout<<set2.size()<<endl;
        for(auto it:set2){
            cout<<it<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
