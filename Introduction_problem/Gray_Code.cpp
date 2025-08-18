#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int total = 1 << n;// total cases
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);// formula of grey code so that only 1 bit is changed 
        /*
        It would go like:
        gray:
        1. 0^0=000
        2. 1^0=001
        3. 010^001=011
        4. 011^001=010        
        */

        for (int j = n - 1; j >= 0; --j) {
            cout << ((gray >> j) & 1);
        }
        cout << endl;
    }
    return 0;
}