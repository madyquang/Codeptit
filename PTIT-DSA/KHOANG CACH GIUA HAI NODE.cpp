#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

void bfs(int start, int end) {
    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    q.push({ start, 0 });
    vis[start] = true;
    while (!q.empty()) {
        int top = q.front().first;
        int l = q.front().second;
        q.pop();

        if (top == end) {
            cout << l << endl;
            return;
        }
        for (int v : adj[top]) {
            if (!vis[v]) {
                q.push({ v, l + 1 });
                vis[v] = true;
            }
        }
    }
}

void testcase() {
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        bfs(u, v);
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}
