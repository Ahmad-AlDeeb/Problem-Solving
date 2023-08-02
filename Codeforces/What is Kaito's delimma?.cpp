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
void fast() {
    ll n,x; cin >> n>>x;
    bitset<32>bs(x);
    vll tar;
    for(ll i{}; i<32; i++)
        if(bs[i]) tar.pb(i);

    vll v;
    for(ll i{}; i<n; i++) {
        ll fri; cin >> fri;
        bitset<32>bs_f(fri);
        bool valid{true};
        for(auto  i:tar) if(!bs_f[i]) valid=false;
        if(valid) v.pb(fri);
    }
    if(v.empty()) {cout << -1; return;}


    map<ll,pair<ll,vll>>f;
    for(auto fri:v) {
        bitset<32>bs_f(fri);
        for(ll i{}; i<32; i++)
            if(bs_f[i]) f[i].F++, f[i].S.pb(fri);
    }


    for(auto p:f)
        if(p.S.F==v.size() && !binary_search(all(tar),p.F))
            {cout << -1; return;}
    cout << v.size();
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
