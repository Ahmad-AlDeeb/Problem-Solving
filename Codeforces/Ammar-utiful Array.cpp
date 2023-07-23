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
const ll N {10004};
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
ll c,tar;
map<ll,ll> neg; ll sum{};
bool valid(ll i, vll &v) {
    ll val = v[i] + (i+1)*(sum-neg[c]);
    return val<=tar;
}
void fast() {
    ll n; cin >> n;
    vll v(n); for(auto &i:v) cin >> i;
    map<ll,vll>color;
    for(ll i{}; i<n; i++) {
        ll x; cin >> x; color[x].pb(v[i]);
    }
    for(auto &vec:color)
        for(ll i{1}; i<vec.S.size(); i++)
            vec.S[i] += vec.S[i-1];


    ll q; cin >> q;
    while(q--) {
        ll x,val; cin >> x >> c >> val;
        if(x==1) {
            sum += val;
            neg[c] += val;
        }
        else {
            tar = val;
            ll l{},r = color[c].size()-1, ind{-1};
            while(l<=r) {
                ll mid = l+(r-l)/2;
                if(valid(mid,color[c])) l=mid+1, ind=mid;
                else           r=mid-1;
            }
            if(ind==-1) cout << 0;
            else cout << ind+1;
            cout << endl;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
