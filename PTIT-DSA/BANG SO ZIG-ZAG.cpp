#include<bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, z;
    cin >> x >> y >> z;

    long long cheo = x + y - 2;
    long long socuoicheotruoc = (cheo + 1) * cheo / 2;
    cout << socuoicheotruoc + y << endl;
    long long cheoz = (-1 + sqrt(1 + 8 * z)) / 2;
    if (cheoz * (cheoz + 1) / 2 == z) --cheoz;
    long long socuoi = cheoz * (cheoz + 1) / 2;
    long long cot = z - socuoi;
    long long hang = cheoz + 2 - cot;
    cout << hang << " " << cot;

    return 0;
}