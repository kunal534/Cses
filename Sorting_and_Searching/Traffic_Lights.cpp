#include<iostream>
#include<set>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n,m;
    std::cin>>n>>m;
    //segment
    std::multiset<int>segments;
    std::set<int>lights;// light places

    lights.insert(0);
    lights.insert(n);
    segments.insert(n);
    long long x;
    for(int i=0;i<m;i++)
    {
        std::cin>>x;
        // sides

        auto right=lights.upper_bound(x);
        // lower bound is not used here as it would give itself as lower bound is <= 
        auto left=std::prev(right);
        
        long long r=*right,l=*left;

        segments.erase(segments.find(r-l));
        segments.insert(x-l);
        segments.insert(r-x);
        lights.insert(x);

        std::cout<<*segments.rbegin()<<" ";
    }
    return 0;
}