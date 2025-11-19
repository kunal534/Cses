#include<iostream>
#include<stack>
#include<vector>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }

    std::stack<std::pair<int,int>>st;
    std::vector<int>ans(n);

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        if(st.empty())ans[i]=0;
        else ans[i]=st.top().second+1;

        st.push({arr[i],i});
    }
    for(auto& it:ans)
    {
        std::cout<<it<<" ";
    }
    return 0;
}