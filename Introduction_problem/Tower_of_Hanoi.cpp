#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>moves;
void solve(int n,int source,int aux,int target){
    if(n==1){
        moves.push_back({source,target});
        return;
    }
    // till n-1 we placed in increase order using target as aux
    solve(n-1,source,target,aux);
    // after the last ring 
    moves.push_back({source,target});
    // from here we have placed the largest ring to the target now we are placing the smaller rings from aux to target
    // using sorce as aux
    solve(n-1,aux,source,target);
}
int main(){
    int n;
    cin>>n;
    solve(n,1,2,3);
    cout<<moves.size()<<"\n";
    for(auto it:moves){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;
}