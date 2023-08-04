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
void increment(ll &val, ll k) {
    val++; if(val>k) val=1;
}
void fast() {
    ll n,k; cin >> n >> k;
    map<ll,ll> freq; bool cool{true};
    vll v(n);
    for(auto &i:v) {
        cin >> i, freq[i]++;
        if(freq[i]>k) cool=false;
    }
    if(!cool) {cout << "NO"; return;}

    map<ll,set<ll>> f;
    vll ans; ll last{};
    for(auto x:v) {
        increment(last,k);
        while(f[x].count(last)) increment(last,k);
        ans.pb(last), f[x].insert(last);
    }
    cout << "YES\n";
    for(auto num:ans) cout << num << " ";
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
