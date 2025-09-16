#include <iostream>
#include <set>
#include <vector>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price; 
        std::cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int maxPrice;
        std::cin >> maxPrice;
        auto it = tickets.upper_bound(maxPrice);// the element just above

        if (it == tickets.begin()) {
            std::cout << -1 << "\n";
        } else {
            --it;// goes the element just lesser or equal to maxPrice
            std::cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}
