#include<iostream>
#include<vector>
#include<queue>
int main()
{
    int n;
    std::cin>>n;

    std::vector<std::vector<int>>grid(n,std::vector<int>(n,-1));
    
    std::queue<std::pair<int,int>>q;

    q.push({0,0});
    grid[0][0]=0;
    int dx[8]={-2,-2,2,2,-1,1,1,-1};
    int dy[8]={1,-1,1,-1,2,2,-2,-2};
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];

            while(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==-1)
            {
                grid[new_x][new_y]=grid[x][y]+1;
                q.push({new_x,new_y});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<grid[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}   
