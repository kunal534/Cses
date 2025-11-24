#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long; // checked by complier and safer for type cast
bool check(long long target,std::vector<long long>&arr,ll sb)
{
    ll curr=0,part=1;
    for(ll it:arr)
    {
        if(it +curr <=target)
        {
            curr+=it;
        }
        else{
            curr=it;
            part++;
            if(part>sb)return false;
        }
    }
    return true;
}
int main()
{
    int n,sb;
    std::cin>>n>>sb;
    std::vector<ll>arr(n);
    long long right=0;
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
        right+=arr[i];
    }
    long long left=*max_element(arr.begin(),arr.end());
    while(left<=right)
    {   
        long long mid=left+(right-left)/2;
        if(check(mid,arr,sb))
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    std::cout<<left<<"\n";
}