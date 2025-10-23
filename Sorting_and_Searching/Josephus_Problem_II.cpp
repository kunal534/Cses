#include<iostream>
#include<vector>
using namespace std;

/*
    the logic is that we will update only that index which needed the current element to calculate there calue
    example for 7 =2^2+ 2^1 + 2^0 hence for 7 we just need to update the value of only 7 and not the rest of previous elmenet 
    for 6 =2^2 + 2^1 so just get the number of elements from it and if we remove 6 then we would need to update both the number of value 
    from index 2 and 1
    
*/

struct BIT{
    int n;
    vector<int>bit;
    BIT(int n):n(n),bit(n+1,0){}
    void add(int i,int delta)
    {
        for(++i;i<=n; i += i&-i )
        {
            // hence for 1+ 1 = 2 so every 2nd element 
            bit[i]+=delta;
        }
    }
    int sum(int index)
    {
        int count=0;
        for(++index;index>0;index-= (index & -index))
        {
            count+=bit[index];
        }
        return count;
    }
    int kth_el(int k)
    {
        int l=0,r=n-1;
        int left=0,right=n-1;
        while(left<=right)
        {
            /*
                Now here the use of BIT is done so we will find the next index with the condition that its sum should be greater or equal
                to k as k is the number of skips we need to make
            */   
           int mid=(left+right)/2;
           if(sum(mid)>=k)
           {
                right=mid-1;
           }
           else{
            left=mid+1;
           }
        }
        return left;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;

    BIT bit(n);
    for(int i=0;i<n;i++)
    {
        bit.add(i,1);
    }

    int pos=0;
    vector<int>ans;
    for(int cur_s=n;cur_s>0;cur_s--)
    {
        pos=(pos+k)%cur_s;
        int index= bit.kth_el(pos+1);
        ans.push_back(index+1);
        bit.add(index,-1);// remove it
    }
    for(int it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}