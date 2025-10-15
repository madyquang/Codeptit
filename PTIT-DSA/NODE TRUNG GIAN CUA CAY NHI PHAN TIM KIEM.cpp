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

void addNode(Node*& root, int x) {
    if (root == NULL) root = new Node(x);
    else if (x < root->data) addNode(root->left, x);
    else addNode(root->right, x);
}

int cnt;

void inorder_node_count(Node*& root) {
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* top = Q.front();
        Q.pop();
        if (top->left != NULL) Q.push(top->left);
        if (top->right != NULL) Q.push(top->right);

        if (top->left != NULL || top->right != NULL) ++cnt;
    }
}

void testcase() {
    int n; cin >> n;
    cnt = 0;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addNode(root, x);
    }
    inorder_node_count(root);
    cout << cnt;
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}