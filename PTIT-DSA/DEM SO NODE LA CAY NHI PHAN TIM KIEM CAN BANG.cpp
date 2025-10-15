#include<bits/stdc++.h>
using namespace std;
#define all(M) M.begin(), M.end()

struct Node {
    int data;
    Node* left, * right;
    Node(int x) {
        this->data = x;
        left = right = NULL;
    }
};

Node* root;

void addNode(Node*& root, int val) {
    if (root == NULL) root = new Node(val);
    else if (root->data > val) addNode(root->left, val);
    else addNode(root->right, val);
}

void search(vector<int>& v, int st, int en) {
    if (st > en) return;
    if (st == en) {
        addNode(root, v[st]);
    }
    else {
        int idx = (st + en) / 2;
        addNode(root, v[idx]);
        search(v, st, idx - 1);
        search(v, idx + 1, en);
    }
}

void leaf_counting(Node*& root) {
    int cnt = 0;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node* top = Q.front();
        Q.pop();
        if (top->left == NULL && top->right == NULL) ++cnt;
        if (top->left != NULL) Q.push(top->left);
        if (top->right != NULL) Q.push(top->right);
    }
    cout << cnt;
}

void testcase() {
    int n; cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    sort(all(v));
    root = NULL;
    search(v, 0, n - 1);
    leaf_counting(root);
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