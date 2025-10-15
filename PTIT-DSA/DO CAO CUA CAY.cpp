#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int u, int cur, int& res) {
    res = max(res, cur);
    for (int v : adj[u]) {
        dfs(adj, v, cur + 1, res);
    }
}

void testcase() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int res = 0;
    dfs(adj, 1, 0, res);
    cout << res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}