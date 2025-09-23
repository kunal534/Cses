#include<iostream>
#include<algorithm>
#include<vector>
int main(){
    int n;
    std::cin>>n;
    long long x,sum=0;
    std::vector<long long>temp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> temp[i];
    }
    std::sort(temp.begin(),temp.end());
    long long l_num=1;
    for(long long curr:temp)
    {
        // the case would be that if curr sum < curr it would means there a gap
        if(l_num<curr)break;
        /*
        but if not then need to add the num as to increase the range
        example before 1,2,3..... res-1

        if added curr
        then 1,2,3,curr, curr+1,,,res+cur-1
        */ 
        l_num+=curr;
    }
    std::cout<<l_num;
    return 0;
}