#include<iostream>

int main(){
    int n,m;
    std::scanf("%d %d",&n,&m);
    const char cs[2][2]={
        {'A','B'},
        {'C','D'}
    };
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            std::cin>>c;
            bool col=(i+j)&1;// choosing the col
            /*
            we choosed to alter only one fied of the matirx so that a alternating pattern can be created instead of checking for 
            every candidate
            */
            bool small=c<'C';// alternating the rows to create a pattern
            std::cout<<cs[small][col];
        }
        std::cout<<"\n";
    }
    return 0;
}