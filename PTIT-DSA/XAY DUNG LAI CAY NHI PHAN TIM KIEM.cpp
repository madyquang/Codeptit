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

void addNode(Node*& root, int val) {
    if (root == NULL) root = new Node(val);
    else if (val < root->data) addNode(root->left, val);
    else addNode(root->right, val);
}

void loadPreorder(Node*& root) {
    cout << root->data << " ";
    if (root->left != NULL) loadPreorder(root->left);
    if (root->right != NULL) loadPreorder(root->right);
}

void testcase() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addNode(root, x);
    }
    loadPreorder(root);
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}