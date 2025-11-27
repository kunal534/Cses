#include<iostream>
#include<vector>
#include<deque>
#include<climits>
#include<algorithm>
using ll = long long;
int main()
{
    ll n,a,b;
    std::cin>>n>>a>>b;
    std::vector<ll>arr(n+1),prev(n+1);
    for(int i=1;i<=n;i++)
    {
        std::cin>>arr[i];
        prev[i]=prev[i-1]+arr[i];
    }
    std::deque<ll>dq;
    ll ans=LLONG_MIN;
    /*
    max sum between r and l would be prev[r]-prev[l]
    r is moving then range of l would be
    l E [(r-b),(r-a)]
    */
    // in deque front side is where the current lowest prev l is present
    for(int r=1;r<=n;r++)
    {
       int new_element=r-a;// this will be added
       if(new_element>=0)
       {
            while(!dq.empty() && prev[dq.back()]>=prev[new_element])
            {
                dq.pop_back();
            }
            dq.push_back(new_element);
       }

       int previous_element=r-b;// removing older ones
       while(!dq.empty() && dq.front()<previous_element)
       {
            dq.pop_front();
       }
       if(!dq.empty())
       {
        ans=std::max(ans,prev[r]-prev[dq.front()]);
       }
    }
    std::cout<<ans<<"\n";
    return 0;
}