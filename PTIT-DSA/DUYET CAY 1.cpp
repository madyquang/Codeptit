#include<bits/stdc++.h>
using namespace std;

int search(int* inorder, int n, int x) {
    for (int i = 0; i < n; i++)
        if (inorder[i] == x) return i;
}

void duyet(int* inorder, int n, int* preorder) {
    int idx = search(inorder, n, preorder[0]);
    if (idx != 0) duyet(inorder, idx, preorder + 1);
    if (idx != n - 1) duyet(inorder + idx + 1, n - idx - 1, preorder + idx + 1);
    cout << preorder[0] << " ";
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, inorder[1001], preorder[1001];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> inorder[i];
        for (int i = 0; i < n; i++) cin >> preorder[i];
        duyet(inorder, n, preorder);
        cout << endl;
    }
    return 0;
}