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
const ll N = 1e5+1;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS = 1e-19;
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
void fast() {
    ll n,m,p; cin >> n >> m >> p;
    vll d1(n); for(auto &i:d1) cin >> i; sort(all(d1));
    vll d2(m); for(auto &i:d2) cin >> i; sort(all(d2));

    vll pre(d2);
    for(ll i{1}; i<m; i++) pre[i] += pre[i-1];

    ll ans{};
    for(ll i{}; i<n; i++) {
        ll diff {p-d1[i]};
        if(diff<=0) {ans += (p*m); continue;}

        auto it = upper_bound(all(d2),diff);
        if(it==d2.end()) {ans += (d1[i]*m + pre[m-1]); continue;}

        ll loc = distance(d2.begin(), it);
        if(!loc) ans += (p*(m-loc));
        else ans += (d1[i]*loc + pre[loc-1]) + (p*(m-loc));
    }
    cout << ans;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
//        cout << endl;
    }
}
