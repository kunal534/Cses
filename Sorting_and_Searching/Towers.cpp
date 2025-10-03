#include<iostream>
#include<set>
#include<vector>
int main(){
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::multiset<int>s;// here question is for smaller not <= so multi occurence can come

    for(int it:arr)
    {
        auto curr=s.upper_bound(it);
        if(curr!=s.end())
        {
            s.erase(curr);
        }
        s.insert(it);
    }
    std::cout<<s.size()<<"\n";
    return 0;
}