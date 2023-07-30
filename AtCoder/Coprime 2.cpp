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
const ll M = 998244353;
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
map<ll,ll> primes1;
void PF1(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        while(n%P[i] == 0)
            n/=P[i], primes1[P[i]]++;
    }

    if(n!=1) primes1[n]++;
}
map<ll,ll> primes2;
void PF2(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        while(n%P[i] == 0)
            n/=P[i], primes2[P[i]]++;
    }

    if(n!=1) primes2[n]++;
}
void fast() {
    ll n,m; cin >> n >> m;
    for(ll i{}; i<n; i++) {ll x; cin >> x; PF1(x);}

    vll ans;
    for(ll i{1}; i<=m; i++) {
        primes2.clear();
        PF2(i);
        bool cool{true};
        for(auto p2:primes2)
            if(primes1[p2.F]) cool=false;
        if(cool) ans.pb(i);
    }
    cout << ans.size() << endl;
    for(auto num:ans) cout << num << endl;

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
