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
ll k;
vll a,h;
ll get_ans(pair<ll, pair<ll,ll>> &sub) {
    ll l {sub.S.F}, r{sub.S.S}, sz {r-l+1};
    if(sub.F <= k) return sz;


    vll pre,suf;
    for(ll i{l}; i<=r; i++) pre.pb(a[i]), suf.pb(a[i]);
    for(ll i{1}; i<sz; i++) pre[i] += pre[i-1];
    reverse(all(suf));
    for(ll i{1}; i<sz; i++) suf[i] += suf[i-1];

    ll ans, tar {sub.F-k};
    // with right only
    auto it = lower_bound(all(suf),tar);
    if(it == suf.end()) return 0;
    else {
        ll to_remove = distance(suf.begin(), it)+1;
        ans = sz-to_remove;
    }

    for(ll i{}; i<sz; i++) {
        ll to_remove{i+1};
        ll new_tar {tar-pre[i]};
        if(new_tar <= 0) return max(ans, sz-to_remove);

        auto it2 = lower_bound(all(suf),new_tar);
        to_remove += distance(suf.begin(), it2)+1;
        ans = max(ans, sz-to_remove);
    }
}
void fast() {
    ll n; cin >> n >> k;
    a = vll(n); for(auto &i:a) cin >> i;
    h = vll(n); for(auto &i:h) cin >> i;

    vector<pair<ll, pair<ll,ll>>> subs;
    for(ll i{}; i<n; i++) {
        pair<ll,ll> sub = {i,i};
        subs.emplace_back(a[i],sub);
    }

    ll tot{},l{},r{};
    bool in{false};
    for(ll i{}; i<n-1; i++) {
        if(in) {
            r=i, tot+=a[i];
            if(h[i]%h[i+1] != 0) {
                in=false;
                pair<ll,ll> sub = {l,r};
                subs.emplace_back(tot, sub);
            }
            else if(h[i]%h[i+1] == 0 and i==n-2) {
                r=i+1, tot+=a[i+1];
                pair<ll,ll> sub = {l,r};
                subs.emplace_back(tot, sub);
            }

        }
        else if(h[i]%h[i+1] == 0) {
            in=true;
            l=r=i;
            tot = a[i];

            if(i == n-2) {
                r=i+1, tot+=a[i+1];
                pair<ll,ll> sub = {l,r};
                subs.emplace_back(tot, sub);
            }
        }
    }

    ll ans{};
    for(auto sub:subs)
        ans = max(ans, get_ans(sub));
    cout << ans;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }
}
