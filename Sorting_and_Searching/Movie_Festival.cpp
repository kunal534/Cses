#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::pair<int,int>>movies(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>movies[i].second>>movies[i].first;
    }
    std::sort(movies.begin(),movies.end());
    int count=0;
    int last_end=0;
    for(auto &it:movies)
    {
        if(it.second>=last_end)//if found a movie which has starting time after the greater/ after ending of first movie which ending time is lowest
        {
            count++;
            last_end=it.first;//updating movie ending time 
        }
    }
    std::cout<<count<<"\n";
    return 0;
}