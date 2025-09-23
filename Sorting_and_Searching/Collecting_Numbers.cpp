#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    std::vector<int> index(n + 1);
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        index[arr[i]] = i;
    }
    
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (index[i + 1] < index[i]) {
            rounds++;
        }
    }
    
    std::cout << rounds << std::endl;
    return 0;
}
