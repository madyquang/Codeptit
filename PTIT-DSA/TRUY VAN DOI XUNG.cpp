#include<bits/stdc++.h>
using namespace std;

void testcase() {
    string s; cin >> s;
    int n; cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'q') {
            int l, r;
            cin >> l >> r;
            string tmp = s;
            reverse(tmp.begin() + l - 1, tmp.begin() + r);
            if (tmp == s) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if (c == 'c') {
            int x;
            char u;
            cin >> x >> u;
            s[x - 1] = u;
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}