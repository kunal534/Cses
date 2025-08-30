#include<iostream>
#include<numeric>
#include <vector>
#include <algorithm>
int main()
{
    int t;
    std::cin>>t;
    while(t--){
        int n,a,b;
        std::cin>>n>>a>>b;
        if(a + b > n || ((a == 0 && b > 0) || (b == 0 && a > 0))) {
           std::cout << "NO\n";
            continue;
        }
        std::cout<<"YES\n";
        std::vector<int>A(n),B(n);
        std::iota(A.begin(),A.end(),1);
        std::iota(B.begin(),B.end(),1);
        int m = a + b;
        if(a==b)// reverse the order of second row
        {
            std::reverse(B.begin(),B.begin()+m);
        }
        else if(a>b){
            // meaning till a we need to right roate elment to that one less than take its place and after a rest m-b will be bigger
            int shift=a%m;
            std::rotate(B.begin(),B.begin()+shift,B.begin()+m);// right shift
        }
        else{
            int shift=b%m;
            std::rotate(B.begin(),B.begin()+(m-shift),B.begin()+m);// left shift
        }
        for (int x : A) std::cout << x << " ";
        std::cout << "\n";
        for (int x : B) std::cout << x << " ";
        std::cout << "\n";
    }
    return 0;
}
/*
LOGIC BEHIND THE ROTATE:

std::rotate(B.begin(), B.begin() + 2, B.begin() + 3):

Range: First m = 3 elements of B, i.e., [1, 2, 3].
first = B.begin() (points to 1).
middle = B.begin() + 2 (points to 3).
last = B.begin() + 3 (points to 4).
Action: Rotate [1, 2, 3] so that the element at middle (3) becomes the first in the range, followed by the elements after it, then the elements before it.
Result: [1, 2, 3] becomes [3, 1, 2].
Full vector B becomes [3, 1, 2, 4] (since only the first m = 3 elements are rotated).

Print A: 1 2 3 4.
Print B: 3 1 2 4.

*/