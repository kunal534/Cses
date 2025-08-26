#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
void backtrack(std::string &s,int index, std::vector<std::string>&ans){

    if(index == s.size())
    {
        ans.push_back(s);
        return;
    }

    std::set<char>seen;
    for(int i=index;i<s.size();i++)
    {
        if(!seen.count(s[i]))
        {
            seen.insert(s[i]);
            std::swap(s[index],s[i]);// swap the element
            backtrack(s,index+1,ans);// go the next index 
            std::swap(s[index],s[i]);// revert the swap 
        }
    }
}
int main(){

    std::string s;
    std::cin>>s;

    std::vector<std::string>ans;
    backtrack(s,0,ans);

    std::sort(ans.begin(),ans.end());
    ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
    
    std::cout<<ans.size()<<std::endl;

    for(const auto& it:ans){
        std::cout<<it<<std::endl;
    }
    return 0;
}