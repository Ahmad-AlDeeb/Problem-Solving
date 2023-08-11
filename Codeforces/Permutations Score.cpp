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
vll P; vector<bool> Prime(1003,true);
void sieve() {
    Prime[0]=Prime[1]=false;
    for(ll i{2}; i<1003; i++) if(Prime[i]) {
            for(ll composite{i*i}; composite<1003; composite+=i)
                Prime[composite]=false;
            P.pb(i);
        }
}

ll div_cnt(ll n) {
    ll cnt{1};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; i++) {
        ll power{};
        while(n%P[i]==0) n/=P[i], ++power;
        cnt *= power+1;
    }
    return (n!=1)? 2*cnt:cnt;
}
vll cnt(N);
void build() {
    for(ll i{1}; i<N; i++) {
        cnt[i] = div_cnt(i)-1;
        cnt[i] += cnt[i-1];
    }
}

ll Fact[N];
void ini_fact() {
    Fact[0]=1;
    for(ll i{1}; i<N; i++)
        Fact[i] = (Fact[i-1]*i)%M;
}

void fast() {
    ll n; cin >> n;
    ll ans = Fact[n]*big_pow(2LL,M-2);
    cout << ((ans%M)*(cnt[n]%M)) % M;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    sieve();
    ini_fact();
    build();
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }
}
