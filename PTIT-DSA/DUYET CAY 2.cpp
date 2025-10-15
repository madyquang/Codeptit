#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left, * right;
    Node(int x) {
        this->val = x;
        left = right = NULL;
    }
};

int find(int* inorder, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == x) return i;
    }
}

void addNode(Node*& root, int* inorder, int n, int* level) {
    root = new Node(level[0]);

    int idx = find(inorder, n, level[0]);
    int tree_left[1001], tree_right[1001], l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (find(inorder, n, level[i]) < idx) tree_left[l++] = level[i];
        else tree_right[r++] = level[i];
    }

    if (idx > 0) addNode(root->left, inorder, idx, tree_left);
    if (idx < n - 1) addNode(root->right, inorder + idx + 1, n - idx - 1, tree_right);
}

void load(Node* root) {
    if (root->left != NULL) load(root->left);
    if (root->right != NULL) load(root->right);
    cout << root->val << " ";
}

void testcase() {
    int n, inorder[1001], level[1001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> level[i];
    Node* root = NULL;
    addNode(root, inorder, n, level);
    load(root);
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}