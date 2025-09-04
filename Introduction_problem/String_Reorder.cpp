#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int main()
{   
    std::string s;
    std::cin>>s;
    int n;
    n=s.size();
    std::vector<int>freq(26,0);
    for(auto it:s)freq[it-'A']++;
    int m=*std::max_element(freq.begin(),freq.end());
    if(m>(n+1)/2)
    {
        std::cout<<"-1"<<"\n";
        return 0;
    }
    s="";
    char last=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(!freq[j])continue;
            if(last=='A'+j)continue;

            freq[j]--;
            // checking if possible
            int remaining=n-i-1;
            int curr_max=*max_element(freq.begin(),freq.end());
            if(curr_max<=(remaining+1)/2)
            {
                s.push_back('A'+j);
                last='A'+j;
                break;
            }
            freq[j]++;
        }
    }
    std::cout<<s;
}