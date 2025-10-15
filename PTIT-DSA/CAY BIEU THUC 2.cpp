#include<bits/stdc++.h>
using namespace std;

bool isOperator(const string& c) {
    return c == "+" || c == "-" || c == "*" || c == "/";
}

int solve(int a, int b, string& str) {
    if (str == "+") return a + b;
    if (str == "-") return a - b;
    if (str == "*") return a * b;
    return a / b;
}

void testcase() {
    int n; cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    stringstream ss(s);
    stack<string> st;
    deque<int> q;
    string w;
    while (ss >> w) {
        if (isOperator(w)) st.push(w);
        else q.push_back(stoi(w));
    }
    while (!st.empty()) {
        int b = q.back();
        q.pop_back();
        int a = q.back();
        q.pop_back();
        string opr = st.top();
        st.pop();
        q.push_front(solve(a, b, opr));
    }
    cout << q.front();
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
        cout << endl;
    }
    return 0;
}