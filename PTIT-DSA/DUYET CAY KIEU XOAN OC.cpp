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

void loadTree(Node*& root) {
    queue<Node*> Q;
    Q.push(root);
    bool left_to_right = false;

    while (!Q.empty()) {
        int sz = Q.size();
        vector<Node*> v;
        for (int i = 0; i < sz; i++) {
            Node* top = Q.front();
            v.push_back(top);
            Q.pop();

            if (top->left != NULL) Q.push(top->left);
            if (top->right != NULL) Q.push(top->right);
        }
        if (!left_to_right) reverse(v.begin(), v.end());
        left_to_right = !left_to_right;
        for (auto x : v) cout << x->data << " ";
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
    loadTree(root);
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