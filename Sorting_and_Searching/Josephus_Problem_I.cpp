#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> children(n);
    for (int i = 0; i < n; i++) children[i] = i + 1;

    vector<int> removal_order;
    int current = -1;  
    int alive = n;
    int diff = 2;      

    while (alive > 0) {
        int count = 0;
        while (count < diff / 2 && alive > 0) {
            int skips = 0;
            while (true) {
                current = (current + 1) % n;
                if (children[current] != -1) {
                    skips++;
                    if (skips == 2) break;
                }
            }
            removal_order.push_back(children[current]);
            children[current] = -1;
            alive--;
            count++;
        }
        diff *= 2;
    }
    for (int i = 0; i < n; i++) {
        cout << removal_order[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}
