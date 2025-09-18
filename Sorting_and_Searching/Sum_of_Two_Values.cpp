#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int a,b;
    std::cin>>a>>b;
    std::vector<std::pair<int,int>>values(a);

    for(int i=0;i<a;i++){
        int x;
        std::cin>>x;
        values[i]={x,i+1};
    }
    std::sort(values.begin(),values.end());
    int left=0,right=a-1;
    while(left<right){
        int sum=values[left].first+values[right].first;
        if(sum==b){
            std::cout<<values[left].second<<" "<<values[right].second<<"\n";
            return 0;
        }
        else if(sum<b)
        {
            left++;
        }
        else{
            right--;
        }
    }
    std::cout<<"IMPOSSIBLE\n";
    return 0;
}