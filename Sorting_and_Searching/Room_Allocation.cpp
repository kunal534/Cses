#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::array<long long,3>>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i][0]>>arr[i][1];
        arr[i][2]=i;
    }

    // sorted based on starting point
    sort(arr.begin(),arr.end(),[&](auto & a,auto &b){
        return a[0]<b[0];
    });
    // departure time,index

    /*
        the idea is that in order for one to check if room is avalible we can simply
        store the element in greater/ascending order so that the smallest ending time can be used first
    */
    std::priority_queue<std::pair<long long,long long>,std::vector<std::pair<long long,long long>>,std::greater<std::pair<long long,long long>>>pq;

    std::vector<long long>ans(n);
    int room=1;
    for(auto&curr:arr)
    {
        long long a=curr[0],b=curr[1];
        long long index=curr[2];
        if(!pq.empty() && pq.top().first<a)// meaning the top one can be used
        {
            auto [d,a_room]=pq.top();
            pq.pop();
            ans[index]=a_room;
            pq.push({b,a_room});
        }else{
            ans[index]=room;
            pq.push({b,room});
            room++;
        }
    }
    std::cout<<room-1<<"\n";
    for(auto &it:ans)
    {
        std::cout<<it<<" ";
    }
    return 0;
}