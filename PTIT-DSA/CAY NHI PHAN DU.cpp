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
    if (root == NULL) root = new Node(u);
    if (root->data == u) {
        Node* p = new Node(v);
        if (c == 'L') root->left = p;
        else root->right = p;
    }
    else {
        if (root->left != NULL) addNode(root->left, u, v, c);
        if (root->right != NULL) addNode(root->right, u, v, c);
    }
}

void checkFull(Node*& root) {
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* top = Q.front();
        Q.pop();
        if ((top->left == NULL && top->right != NULL) || (top->right == NULL && top->left != NULL)) {
            cout << 0;
            return;
        }
        if (top->left != NULL) Q.push(top->left);
        if (top->right != NULL) Q.push(top->right);
    }
    cout << 1;
}

void testcase() {
    int n;
    cin >> n;
    Node* root = NULL;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root, u, v, c);
    }
    checkFull(root);
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}