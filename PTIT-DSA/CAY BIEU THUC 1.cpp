#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left, * right;
    Node(char c) {
        this->data = c;
        left = right = NULL;
    }
};

bool isOperator(char& c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void buildTree(string& s, Node*& root) {
    stack<Node*> st;
    for (auto& c : s) {
        Node* p = new Node(c);
        if (!isOperator(c)) st.push(p);
        else {
            Node* b = st.top();
            st.pop();
            Node* a = st.top();
            st.pop();
            p->left = a;
            p->right = b;
            st.push(p);
        }
    }
    root = st.top();
}

void inorder(Node*& root) {
    if (root->left) inorder(root->left);
    cout << root->data;
    if (root->right) inorder(root->right);
}

void testcase() {
    string s;
    cin >> s;
    Node* root = NULL;
    buildTree(s, root);
    inorder(root);
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}