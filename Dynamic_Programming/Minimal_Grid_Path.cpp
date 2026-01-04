#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string ans;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<bool>>seen(n,vector<bool>(n,false));
    vector<pair<int,int>>curr;
    curr.push_back({0,0});
    ans.push_back(arr[0][0]);
    seen[0][0]=true;
    for(int i=1;i<=2*n-2;i++)
    {
        char best='Z';
        vector<pair<int,int>>next;
        for(auto [x,y]:curr)
        {
            if(x+1<n)
            {
                best=min(best,arr[x+1][y]);
            }
            if(y+1<n)
            {
                best=min(best,arr[x][y+1]);
            }
        }
        
        for(auto [x,y]:curr)
        {
            if(x+1 < n && arr[x+1][y]==best && !seen[x+1][y])
            {
                seen[x+1][y]=true;
                next.push_back({x+1,y});
            }
            if(y+1<n && arr[x][y+1]==best && !seen[x][y+1])
            {
                seen[x][y+1]=true;
                next.push_back({x,y+1});
            }
        }
        ans.push_back(best);
        curr.swap(next);
    }
    cout<<ans<<"\n";
    return 0;
}
