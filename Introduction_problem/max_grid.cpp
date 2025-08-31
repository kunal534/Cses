#include<iostream>
#include<vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>grid(n,std::vector<int>(n,0));

    std::vector<std::vector<bool>> colUsed(n,std::vector<bool>(2*n, false));
    std::vector<std::vector<bool>> rowUsed(n, std::vector<bool>(2*n, false));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int index=0;
            while(colUsed[j][index] || rowUsed[i][index])index++;

            grid[i][j]=index;
            colUsed[j][index]=true;
            rowUsed[i][index]=true;
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