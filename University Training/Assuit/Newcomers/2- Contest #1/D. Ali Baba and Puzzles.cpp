#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
using namespace std;

int main() { IOS
    ll a{}, b{}, c{}, d{}; cin >> a >> b >> c >> d;
    if(a+b-c==d || a+b*c==d || a-b+c==d || a-b*c==d || a*b+c==d || a*b-c==d)
        cout << "YES";
    else cout << "NO";
}
