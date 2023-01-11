#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
using namespace std;

int main() { IOS
    ll a{}, b{}, k{}; cin >> a >> b >> k;
    if(a%k==0 && b%k==0)      cout << "Both";
    else if(a%k==0 && b%k!=0) cout << "Memo";
    else if(a%k!=0 && b%k==0) cout << "Momo";
    else                      cout << "No One";
}
