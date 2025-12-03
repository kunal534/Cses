#include<iostream>
#include<algorithm>
int main()
{
    int n;
    std::cin>>n;
    int step=0;
    while(n>0)
    {
        int x=n;
        int maxi=0;
        while(x)
        {
            maxi=std::max(maxi,x%10);
            x=x/10;
        }
        n-=maxi;
        step++;
    }
    std::cout<<step<<"\n";
    return 0;
}