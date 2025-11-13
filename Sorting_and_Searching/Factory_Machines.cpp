#include<iostream>
/*
    The logic is that we  need to find the minimum number 
    of time so taking binary as making a full pick and choice would be a nightmare
*/
#include<vector>
#include <algorithm>
int main(){
    long long a,b;
    std::cin>>a>>b;
    std::vector<long long>arr(a);
    for(long long i=0;i<a;i++)
    {
        std::cin>>arr[i];
    }
    long long low=0,high=*max_element(arr.begin(),arr.end())*b;
    while(low<high)
    {
        long long mid=low+((high-low)>>1);
        long long curr=0;
        for(long long& it:arr)
        {
            curr+=mid/it;// adding the sum of task each machine with there respective time period can do 
            if(curr >= b)break;
        }
        if(curr>=b)// meaning in the current time the number of task are more
        {
            high=mid;
        }else{
            low=mid+1;
        }
    }
    std::cout<<low<<"\n";
    return 0;
}