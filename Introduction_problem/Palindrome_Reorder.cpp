#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;

    int freq[26]={0};
    long long count=0;

    for(char curr:s){
        freq[curr-'A']++;
        count++;
    }
    int odd_count=0,odd_char=-1;
    for(int i=0;i<26;i++){
        if(freq[i]%2!=0){
            odd_count++;
            odd_char=i;
        }
    }

    if(odd_count>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }

    string ans(s.size(),' ');
    int left=0,right=s.size()-1;
    for(int i=0;i<26;i++){
        while(freq[i]>=2){
            ans[left++]=i+'A';
            ans[right--]=i+'A';
            freq[i]-=2;
        }
    }
    if(odd_count){
        ans[left]='A'+odd_char;
    }
    cout<<ans<<"\n";
    return 0;
}