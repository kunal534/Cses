#include<iostream>
#include<math.h>
int main()
{
    int n;
    std::cin>>n;
    while(n--)
    {
        long long num;
        std::cin>>num;

        long long digit_size=1;
        long long number_visit=9;

        while(num>digit_size*number_visit)
        {
            num-=digit_size*number_visit;
            digit_size++;
            number_visit*=10;
        }
        // finding the exact number

        long long start=(long long)std::pow(10,digit_size-1);
        long long ans=start+(num-1)/digit_size;
        int digit_index=(num-1)%digit_size;
        
        std::string s=std::to_string(ans);
        std::cout<<s[digit_index]<<"\n";
    }
}