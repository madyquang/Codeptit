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

void addNode(Node*& root, int u, int v, char c) {
    if (root == NULL) {
        root = new Node(u);
        Node* p = new Node(v);
        if (c == 'L') root->left = p;
        else root->right = p;
    }
    else {
        if (root->val == u) {
            Node* p = new Node(v);
            if (c == 'L') root->left = p;
            else root->right = p;
        }
        else {
            if (root->left != NULL) addNode(root->left, u, v, c);
            if (root->right != NULL) addNode(root->right, u, v, c);
        }
    }
}

void checkLeaf(Node*& root) {
    set<int> se;

    queue<pair<Node*, int>> Q;
    Q.push({ root, 1 });

    while (!Q.empty()) {
        Node* top_node = Q.front().first;
        int level = Q.front().second;
        Q.pop();

        if (top_node->left == NULL && top_node->right == NULL) {
            se.insert(level);
            continue;
        }
        if (top_node->left != NULL) Q.push({ top_node->left, level + 1 });
        if (top_node->right != NULL) Q.push({ top_node->right, level + 1 });
    }
    cout << (se.size() == 1);
}

void testcase() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root, u, v, c);
    }
    checkLeaf(root);
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}