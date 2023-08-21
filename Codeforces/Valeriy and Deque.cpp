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
vector<pair<ll,ll>> ans1,ans2;
ll n, mx{};
void do_op(deque<ll> &dq) {
    ll a{dq[0]}, b{dq[1]};
    dq.pop_front(); dq.pop_front();

    dq.push_front(max(a,b));
    dq.push_back(min(a,b));
}
void build(deque<ll> &dq) {
    while(dq.front() != mx) {
        ans1.emplace_back(dq[0],dq[1]);
        do_op(dq);
    }
    for(ll i{}; i<n-1; i++) {
        ans2.emplace_back(dq[0],dq[1]);
        do_op(dq);
    }
}

void fast() {
    ll q; cin >> n >> q;
    deque<ll> dq(n);
    for(auto &i:dq) cin >> i, mx=max(mx,i);
    build(dq);

    while(q--) {
        ll m; cin >> m;
        if(m <= ans1.size())
            cout << ans1[m-1].F << " " << ans1[m-1].S;
        else {
            m -= (ll)ans1.size();
            m %= (ll)ans2.size();

            if(!m) cout << ans2.back().F << " " << ans2.back().S;
            else cout << ans2[m-1].F << " " << ans2[m-1].S;
        }
        cout << endl;
    }
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
