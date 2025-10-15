#include<bits/stdc++.h>
using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}