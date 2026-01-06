#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    int sum=std::accumulate(arr.begin(),arr.end(),0);
    std::vector<bool>ans(sum+1,false);
    ans[0]=true;
    int count=0;
    for (int x : arr)
    {
        for (int s = sum; s >= x; s--)
        {
            if (ans[s - x])
             {  if (!ans[s]) count++;
                ans[s] = true;
             }
        }
    }
    std::cout<<count<<"\n";
    for(int i=arr[0];i<=sum;i++)
    {
        if(ans[i])
        {
            std::cout<<i<<" ";
        }
    }
    return 0;
}