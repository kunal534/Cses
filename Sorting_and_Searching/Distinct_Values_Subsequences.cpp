#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> freq;
    for(int x : arr) {
        freq[x]++;
    }
    
    /*
        Logic is from combinators
        choices:
        1. we can select 1 element from f frequenct 
        2. we dont select any occurence of that element
        so total choice for each element = f+1 
        now for the rest of independent elements : submisson(f+1)
        The choices for each value are independent. By the product rule in combinatorics:
        we would be multiplying it 
        hence 
    */

   long long result = 1;
   for(auto& [val, count] : freq) {
       result = (result * (count + 1)) % MOD;
   }

    
    // Subtract 1 for the empty subsequence
    result = (result - 1 + MOD) % MOD;
    
    cout << result << "\n";
    return 0;
}