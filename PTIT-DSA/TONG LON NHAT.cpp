#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int x) {
        this->data = x;
        left = right = NULL;
    }
};

void addNode(Node*& root, int u, int v, char c) {
    if (!root) root = new Node(u);
    if (root->data == u) {
        Node* p = new Node(v);
        if (c == 'L') root->left = p;
        else root->right = p;
    }
    else {
        if (root->left) addNode(root->left, u, v, c);
        if (root->right) addNode(root->right, u, v, c);
    }
}

int res;

int load(Node*& root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    int sumLeft = load(root->left), sumRight = load(root->right);
    if (!root->left) return sumRight + root->data;
    if (!root->right) return sumLeft + root->data;
    if (root->left && root->right) {
        res = max(res, sumRight + sumLeft + root->data);
        return max(sumLeft, sumRight) + root->data;
    }
}

void testcase() {
    int n; cin >> n;
    res = INT_MIN;
    Node* root = NULL;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root, u, v, c);
    }
    load(root);
    cout << res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}