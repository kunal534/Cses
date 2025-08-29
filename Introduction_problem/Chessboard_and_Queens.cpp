#include<iostream>
// diagonal1 direction-> top-left to bottom-right numbering starts from [last-row][0]
// diagonal2 direction-> bottom-left to top-right numbering starts from [0][0]
int solve(int row,bool col[8],bool diagonal1[15],bool diagonal2[15],char board[8][8])
{
    if(row==8)
    {
        return 1;
    }
    int ways=0;
    for(int c=0;c<8;c++)
    {
        if(!col[c] && !diagonal1[row+c] && !diagonal2[row-c+7] && board[row][c]!='*')
        {
            col[c]=diagonal1[row+c]=diagonal2[row-c+7]=true;
            ways+=solve(row+1,col,diagonal1,diagonal2,board);
            col[c]=diagonal1[row+c]=diagonal2[row-c+7]=false;
        }
    }
    return ways;
}
int main()
{
    char board[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            std::cin>>board[i][j];
        }
    }
    bool col[8]={false}, diagonal1[15]={false}, diagonal2[15]={false};

    int ways=solve(0,col,diagonal1,diagonal2,board);

    std::cout<<ways<<"\n";

}