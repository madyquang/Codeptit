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
    if (root == NULL) {
        root = new Node(u);
        Node* p = new Node(v);
        if (c == 'L') root->left = p;
        else root->right = p;
    }
    else {
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
}

void checkPerfect(Node*& root) {
    int preSize = 0;
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        int curSize = Q.size();
        if (preSize != 0 && curSize != preSize * 2) {
            cout << "No";
            return;
        }
        preSize = curSize;

        for (int i = 0; i < curSize; i++) {
            Node* top = Q.front();
            Q.pop();

            if (top->left != NULL) Q.push(top->left);
            if (top->right != NULL) Q.push(top->right);
        }
    }
    cout << "Yes";
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
    checkPerfect(root);
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