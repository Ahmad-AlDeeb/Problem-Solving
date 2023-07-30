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
const ll N = 10000007;
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
vll P; vector<bool> Prime(N,true);
void sieve() { // (1e7 < 1s) <-- O(n loglogn)
    Prime[0]= Prime[1]=false;

    for(ll i{2}; i<N; ++i) if(Prime[i]) {
            for(ll composite{i+i}; composite<N; composite+=i)
                Prime[composite]=false;
            P.pb(i);
        }
}
ll PP_fact(ll n, ll p) { // Legendre's formula
    ll exp{};
    for(ll i{p}; i<=n; i*=p)
        exp += n/i;
    return exp;
}
void fast() {
    ll n; cin >> n;
    map<ll,ll> f;
    for(ll i{}; i<P.size(); i++) {
        if(PP_fact(n,P[i]))
            f[P[i]] = PP_fact(n,P[i]);
        else break;
    }

    ll ans{};
    for(auto p:f) {
        ans += p.S + (ans*p.S);
        ans %= M;
    }
    cout << (ans+1)%M;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    sieve();
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
