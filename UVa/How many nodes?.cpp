#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////
const ll N = 100;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS {1e-19};
const ld PI {3.14159265358979323846};
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
vll C {0,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
void fast() {
    ll n;
    while(cin >> n) {
        for(ll i{1}; i<C.size(); i++)
            if(C[i]==n) {cout << i; break;}
        cout << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
