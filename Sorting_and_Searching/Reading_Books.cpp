#include<iostream>
#include<algorithm>
int main(){
    int n;
    std::cin>>n;
    long long sum=0,maxi=0;
    /*
        The logic was simple:
        1. Either the time needed would be the 2*max as it would cover the rest of smaller one
        2. or the sum of all in case of this


        eg: 2,8,2,3,5,6,4
        A:2,2,3,5,8,6,4
        B:8,2,2,3,5,4,6
        
        Hence, for your doubt the answer would be sum of array
    */
    while(n--)
    {
        long long x;
        std::cin>>x;
        sum+=x;
        maxi=std::max(maxi,x);
    }
    std::cout<<std::max(sum,2*maxi)<<"\n";
    return 0;
}