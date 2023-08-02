#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll int
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////
const ll N = 1e5+5;
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
set<pair<ll,ll>> s;
map<ll,vector<pair<ll,ll>>> d;

void get_div(ll x) {
    vector<pair<ll,ll>> div;
    for(ll i{1}; i*i<=x; i++)
        if(x%i == 0) {
            div.emplace_back(i,x/i);
            if(i*i != x) div.emplace_back(x/i, i);
        }
    d[x] = div;
}
void fast() {
    ll n; cin >> n;
    vector<pair<ll,ll>> ans;
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        if(!d.count(x)) get_div(x);
        if(d[x].empty()) {cout << "NO"; return;};

        ans.pb(d[x].back());
        d[x].pop_back();
    }


    cout << "YES\n";
    for(auto p:ans) cout << p.F << " " << p.S << endl;
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
