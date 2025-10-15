#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
vector<int> v;

void input()
{
    cin >> n;
    v.resize(n);
    for (int &x : v)
        cin >> x;
}

void solve()
{
    int dpl[n] = {}, dpr[n] = {};
    dpl[0] = dpr[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
            dpl[i] = dpl[i - 1] + 1;
        else
            dpl[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
            dpr[i] = dpr[i + 1] + 1;
        else
            dpr[i] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dpl[i] + dpr[i] - 1);
    cout << res;
}

void testCase()
{
    input();
    solve();
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while (t--)
    {
        testCase();
        cout << endl;
    }
    return 0;
}
