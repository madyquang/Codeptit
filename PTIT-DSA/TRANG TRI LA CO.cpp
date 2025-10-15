#include<bits/stdc++.h>
using namespace std;
#define all(M) M.begin(), M.end()

int main() {
    int n; cin >> n;
    vector<int> st(n), en(n);
    for (int i = 0; i < n; i++) {
        cin >> st[i] >> en[i];
    }
    sort(all(st));
    sort(all(en));
    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        int count_st = upper_bound(all(st), c) - st.begin();
        int count_en = lower_bound(all(en), c) - en.begin();
        cout << count_st - count_en << endl;
    }
    return 0;
}