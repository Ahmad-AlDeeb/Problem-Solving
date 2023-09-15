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
const ll N = 1e7;
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
vll NGE(N);
void get_NGE(vll v, ll n) {
    stack<ll> s;
    s.push(v[0]);

    for (ll i = 1; i<n; i++) {
        if (s.empty()) {
            s.push(v[i]); continue;
        }

        while (!s.empty() and s.top() < v[i]) {
            NGE[s.top()] = i;
            s.pop();
        }
        s.push(v[i]);
    }
}
void fast() {
    ll n; cin >> n;
    vll v(n); for(auto &i:v) cin >> i;
    get_NGE(v,n);

    vll ans(n); ans.back() = v.back();
    for(ll i{n-2}; i>=0; i--) {
        ll cnt {n-i};
        ll nge {NGE[v[i]]};

        if(!nge) ans[i] = cnt*v[i];
        else ans[i] = (nge-i)*v[i] + ans[nge];
    }

    ll sum{};
    for(auto s:ans) sum += s;
    cout << sum;
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
