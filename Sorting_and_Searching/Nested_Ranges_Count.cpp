#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Fenwick{
    int n;
    vector<int>bit;
    Fenwick(int n):n(n),bit(n+1,0){}
    void update(int x,int delta) {
        for(;x<=n;x+= x&-x) {
            bit[x]+=delta;
        }
    }
    int query(int i){
        int s=0;
        for(;i>0;i -= i &-i) s+=bit[i];
        return s;
    }
    int range(int l,int r) {
        if(l>r)return 0;
        return query(r)-query(l-1);
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<array<long long,3>>arr(n);
    vector<long long>endings;
    for(int i=0;i<n;i++) {
        cin>>arr[i][0]>>arr[i][1];
        arr[i][2]=i; // store original index
        endings.push_back(arr[i][1]);
    }

    // Coordinate compression
    sort(endings.begin(),endings.end());
    endings.erase(unique(endings.begin(),endings.end()), endings.end());


    // Sort by x ascending, y descending
    sort(arr.begin(),arr.end(),[&](auto& a,auto& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    });

    auto get=[&](long long curr){
        return static_cast<int>(lower_bound(endings.begin(),endings.end(),curr)-endings.begin())+1;
    };
    
    vector<long long>contains(n),containedby(n);

    // containedby
    Fenwick f1(n);
    for(int i=0;i<n;i++)
    {
        int y_index=get(arr[i][1]);// does a compresion for space optimization
        containedby[arr[i][2]]=f1.range(y_index,n);// taking chunk from final - curr as it y greater than curr could have him
        /*
            Sorted order: [start asc, end desc]
            [1,6]  -> end=6 -> range(2,3)=0  [BIT: empty]           -> containedby[0]=0
            [2,4]  -> end=4 -> range(1,3)=1  [BIT: has [1,6]]       -> containedby[1]=1
            [3,6]  -> end=6 -> range(2,3)=1  [BIT: has [1,6],[2,4]] -> containedby[3]=1  
            [4,8]  -> end=8 -> range(3,3)=0  [BIT: has all previous]-> containedby[2]=0
        */
        f1.update(y_index,1);
    }
    //contains
    Fenwick f2(n);
    for(int i=n-1;i>=0;i--)
    {
        int y_index=get(arr[i][1]);
        contains[arr[i][2]]=f2.query(y_index);// taking from curr to back with samller index and ys with bigger than current
        /*
            Processing RIGHT to LEFT:
            [4,8]  -> end=8 -> query(3)=0  [BIT: empty]           -> contains[2]=0
            [3,6]  -> end=6 -> query(2)=0  [BIT: has [4,8]]       -> contains[3]=0
            [2,4]  -> end=4 -> query(1)=0  [BIT: has [4,8],[3,6]] -> contains[1]=0
            [1,6]  -> end=6 -> query(2)=2  [BIT: has all others]  -> contains[0]=2
        */
        f2.update(y_index,1);
    }

    for(auto &it:contains)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto& it:containedby)
    {
        cout<<it<<" ";
    }
    return 0;
}