#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left, * right;
    Node(int x) : val(x), left(NULL), right(NULL) {};
};

void addNode(Node*& root, int u, int v, char c) {
    if (root == NULL) {
        root = new Node(u);
        Node* leaf = new Node(v);
        if (c == 'L') root->left = leaf;
        else root->right = leaf;
    }
    else {
        if (root->val == u) {
            Node* leaf = new Node(v);
            if (c == 'L') root->left = leaf;
            else root->right = leaf;
        }
        else {
            if (root->left != NULL) addNode(root->left, u, v, c);
            if (root->right != NULL) addNode(root->right, u, v, c);
        }
    }
}

void load(Node* root) {
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node* top = Q.front();
        Q.pop();

        cout << top->val << " ";
        if (top->left != NULL) Q.push(top->left);
        if (top->right != NULL) Q.push(top->right);
    }
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
    load(root);
    return;
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}