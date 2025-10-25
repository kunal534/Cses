#include<iostream>
#include<vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<tuple<int,int,int>> range; 
    range.reserve(n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        range.emplace_back(l,r,i);
    }
    sort(range.begin(),range.end(),[](auto &a,auto &b){
        if(get<0>(a)==get<0>(b))return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });
    // sorted 
    vector<int>contains(n),contained(n);
    int r_max=0;
    for(auto& [l,r,i]:range){
        if(r<=r_max)contained[i]=1;// if curr r is less than max it means in contained in somewher previous ones
        r_max=max(r_max,r);
    }
    int min_r=INT_MAX;
    for(int i=n-1;i>=0;i--){
        auto &[l,r,index]=range[i];
        if(r>=min_r) contains[index]=1;// if curr r is greater than forwards one means it would contains somone as l is already samller and r is bigger
        min_r=min(min_r,r);
    }
    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained) cout << x << " ";
    return 0;
}
