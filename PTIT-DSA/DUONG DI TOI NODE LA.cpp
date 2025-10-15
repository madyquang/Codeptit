#include<bits/stdc++.h>
using namespace std;

vector<set<int>> adj;
vector<int> par;
vector<int> res;
vector<vector<int>> RES;

void tracing(int u) {
    res.push_back(u);
    if (u != 1) tracing(par[u]);
}

void dfs(vector<set<int>>& adj, int u) {
    if (adj[u].empty()) {
        res.clear();
        tracing(u);
        reverse(res.begin(), res.end());
        RES.push_back(res);
    }

    else {
        for (int v : adj[u]) {
            par[v] = u;
            dfs(adj, v);
        }
    }
}

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a.back() < b.back();
}

void testcase() {
    int n; cin >> n;
    RES.clear();
    adj.assign(n + 1, {});
    par.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }
    dfs(adj, 1);
    par[1] = 1;
    sort(RES.begin(), RES.end(), cmp);
    for (auto x : RES) {
        for (int y : x) cout << y << " ";
        cout << endl;
    }
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