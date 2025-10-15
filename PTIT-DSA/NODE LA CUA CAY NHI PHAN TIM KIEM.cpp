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

vector<int> leaf;

void loadLeaf(Node*& root) {
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* top = Q.front();
        Q.pop();
        if (top->left != NULL) Q.push(top->left);
        if (top->right != NULL) Q.push(top->right);

        if (top->left == NULL && top->right == NULL) leaf.push_back(top->data);
    }
}

void testcase() {
    int n; cin >> n;
    leaf.clear();
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addNode(root, x);
    }
    loadLeaf(root);
    sort(leaf.begin(), leaf.end());
    for (int x : leaf) cout << x << " ";
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}