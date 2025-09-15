#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    vector<long long>values(a);
    for(int i=0;i<a;i++)
    {
        cin>>values[i];
    }
    sort(values.begin(),values.end());
    int i=0,j=a-1,count=0;
    while(i<=j)
    {
        if(values[i]+values[j]<=b)
        {
            i++;
            j--;
        }
        else{
            j--;
        }
        count++;
    }
    cout<<count;
    return 0;
}