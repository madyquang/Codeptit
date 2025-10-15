#include<bits/stdc++.h>
using namespace std;

map<int, int> dp[100005];

void add(int len, int x, int y) {
    auto it1 = dp[len].lower_bound(x);
    auto it2 = it1;
    while (it2->second > y && it2 != dp[len].end()) ++it2;

    dp[len].erase(it1, it2);

    dp[len].insert({ x, y });
}

bool check(int len, int x, int y) {
    auto it = dp[len].lower_bound(x);
    if (it == dp[len].begin()) return false;
    --it;
    return it->second < y;
}

int main() {
    int n; cin >> n;
    int res = 0;
    add(0, INT_MIN, INT_MIN);
    while (n--) {
        int x, y;
        cin >> x >> y;

        int l = 0, r = res;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m, x, y)) l = m + 1;
            else r = m - 1;
        }
        if (res == l - 1) res = l;
        add(l, x, y);
    }
    cout << res;
    return 0;
}