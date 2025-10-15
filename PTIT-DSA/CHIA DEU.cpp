#include<bits/stdc++.h>
using namespace std;
#define all(M) M.begin(), M.end()

int n, k, res;
vector<int> v;
void Try(int st, int cursum, int target, int cnt) {
    if (st == n && cnt == k) {
        ++res;
        return;
    }
    for (int j = st; j < n; j++) {
        cursum += v[j];
        if (cursum == target) Try(j + 1, 0, target, cnt + 1);
    }
}

int main() {
    cin >> n >> k;
    v.resize(n);
    for (int& x : v) cin >> x;
    int sum = accumulate(all(v), 0);
    if (sum % k != 0) cout << 0;
    else {
        Try(0, 0, sum / k, 0);  // start, cursum, target, curcount
        cout << res;
    }
    return 0;
}