#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
using namespace std;

int main() { IOS
    int a{}, b{}; cin >> a >> b;
    if(a==0 && b==0) {cout << "NO"; return 0;}
    if(abs(a-b) < 2) cout << "YES";
    else cout << "NO";
}
