#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
int main() {

    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        pos[arr[i]] = i;
    }
    /*
        conflict pair :
        u any index
        value[u]>values[u+1]
        pos[u]<pos[u+1]


    */
    auto contributor = [&](int x) -> int {
        if (x < 1 || x >= n) return 0;// not possible case
        return pos[x] > pos[x + 1] ? 1 : 0;// checking if pos[x]>pos[x+1] for eg pos[2]>pos[3] area of conflict
    };

    int rounds = 1;
    for (int i = 1; i < n; i++) rounds += contributor(i);

    while (m--) {
        int a, b;
        std::cin >> a >> b;
        int u = arr[a], v = arr[b];

        std::set<int> check = {u, u-1, v, v-1};
        // taking elementing adjoint to the exchange
        for (int x : check) rounds -= contributor(x);

        std::swap(arr[a], arr[b]);
        std::swap(pos[u], pos[v]);

        for (int x : check) rounds += contributor(x);// rechecking if exchanged add any

        std::cout << rounds << "\n";
    }
}
