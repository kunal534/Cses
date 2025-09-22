#include<climits>
#include<iostream>
int main()
{
    int n;
    std::cin>>n;
    long long curr=0,maxi=INT_MIN,x;
    while(n--)
    {   
        std::cin>>x;
        curr+=x;
        maxi=std::max(maxi,curr);
        if(curr<0)
        {
            curr=0;
        }
    }
    std::cout<<maxi;
    return 0;
}