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
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
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
ll max_sub(vll &v) {
    ll mx {-MAX}, sum{};
    for (ll i{}; i<v.size(); i++) {
        sum += v[i];
        mx = max(mx,sum);
        if (sum < 0) sum = 0;
    }
    return mx;
}
void fast() {
    ll n; cin >> n;
    ll mx{-MAX};
    vll v1,v2;
    for(ll i{1}; i<=n; i++) {
        ll x; cin >> x;
        mx = max(mx,x);

        if(i&1) {if(x>=0) v1.pb(x);}
        else    {if(x>=0) v2.pb(x);}
    }
    cout << max({mx, max_sub(v1), max_sub(v2)});
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    while(tc--) {
        fast();
        cout << endl;
    }
}
 
