#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
using namespace std;
// dywang
typedef long long ll;



int main()
{
    int n;
    cin >> n;
    for(int i = 2; i * i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
        ++cnt;
        n /= i;
        }
        if(cnt != 0) cout << i << " " << cnt << endl;
    }
    if(n != 1) cout << n << " " << "1";
    return 0;
}
