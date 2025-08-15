#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    
    int max_count = 1, curr = 1;
    int n = s.length();
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            curr++;
        }
        else{
            max_count=max(max_count,curr);
            curr=1;
        }
    }
    max_count=max(max_count,curr);
    cout<<max_count<<endl;
}