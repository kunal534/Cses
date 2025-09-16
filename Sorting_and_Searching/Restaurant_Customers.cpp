#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
int main()
{
    int a;
    std::cin>>a;
    std::vector<int>v1(a),v2(a);
    for(int i=0;i<a;i++)
    {
        std::cin>>v1[i]>>v2[i];
    }
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());

    int curr=0,max_curr=0;
    int i=0,j=0;
    while(i<a && j<a)
    {
        if(v1[i] < v2[j])
        {
            curr++;
            max_curr=std::max(max_curr,curr);
            i++;
        }else{
            curr--; // removing the one which is aligned with the previous v2[j];
            j++;
        }
    }
    std::cout<<max_curr<<"\n";
    return 0;
}