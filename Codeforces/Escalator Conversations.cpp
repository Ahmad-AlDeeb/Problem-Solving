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
const ll N = 31;
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
void fast() {
    ll n,m,k,h; cin>>n>>m>>k>>h;
    vll v(n); for(auto &i:v) cin >> i;

    vll steps(m+1);
    for(ll i{1}; i<=m; i++)
        steps[i] = i*k;
    vll possible;
    for(ll i{1}; i<=m; i++)
        for(ll j{i+1}; j<=m; j++)
            possible.pb(steps[j]-steps[i]);
    sort(all(possible));

    ll ans{};
    for(auto p:v) {
        ll d = abs(p-h);
        if(binary_search(all(possible),d)) ans++;
    }
    cout << ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
        cout << endl;
    }
}
