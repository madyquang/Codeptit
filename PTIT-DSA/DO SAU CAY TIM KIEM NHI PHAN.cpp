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

int deep(Node*& root) {
    int cnt = -1;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        ++cnt;
        int sz = Q.size();
        for (int i = 0; i < sz; i++) {
            Node* top = Q.front();
            Q.pop();
            if (top->left != NULL) Q.push(top->left);
            if (top->right != NULL) Q.push(top->right);
        }
    }
    return cnt;
}

void testcase() {
    int n; cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addNode(root, x);
    }
    cout << deep(root);
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}