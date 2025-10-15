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

void checkSimilar(Node*& root1, Node*& root2, bool& isSimilar) {
    if (!isSimilar) return;
    if (root1->data != root2->data) {
        isSimilar = false;
        return;
    }
    if (root1->left != NULL && root2->left != NULL) checkSimilar(root1->left, root2->left, isSimilar);
    if (root1->right != NULL && root2->right != NULL) checkSimilar(root1->right, root2->right, isSimilar);
}

void testcase() {
    int n; cin >> n;
    Node* root1 = NULL;
    while (n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root1, u, v, c);
    }

    int m; cin >> m;
    Node* root2 = NULL;
    while (m--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        addNode(root2, u, v, c);
    }
    bool isSimilar = true;
    checkSimilar(root1, root2, isSimilar);
    cout << isSimilar;
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}