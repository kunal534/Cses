#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    vector<long long> applicants(n);
    vector<long long> apartments(m);
    for(int i=0;i<n;i++)
    {
        cin>>applicants[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>apartments[i];
    }
    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());

    int i=0,j=0,count=0;
    while(i<n && j<m)
    {
        if(apartments[j]<applicants[i]-c)
        {
            j++;
        }
        else if (apartments[j]>applicants[i]+c)
        {
            i++;
        }else{
            count++;
            i++;
            j++;
        }
    }
    cout<<count<<"\n";
    return 0;
}