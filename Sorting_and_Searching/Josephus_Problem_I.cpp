#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int x):val(x),next(nullptr){}
};
int main(){
    int n;cin>>n;
    vector<int>ans;
    Node *srt=new Node(0);
    Node *tmp=srt;
    for(int i=1;i<n;i++){
        Node *cur=new Node(i);
        srt->next=cur;
        srt=cur;
    }
    srt->next=tmp;
    while(ans.size()!=n){
        ans.push_back(tmp->next->val);
        tmp->next=tmp->next->next;
        tmp=tmp->next;
    }
    for(int i:ans)cout<<i+1<<" ";
}