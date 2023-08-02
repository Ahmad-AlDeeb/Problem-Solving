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
vll P; vector<bool> Prime(N,true);
void sieve() { // (1e7 < 1s) <-- O(n loglogn)
    Prime[0]= Prime[1]=false;

    for(ll i{2}; i<N; ++i) if(Prime[i]) {
            for(ll composite{i+i}; composite<N; composite+=i)
                Prime[composite]=false;
            P.pb(i);
        }
}
map<ll,ll> PF(ll n) {
    map<ll,ll> f;
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        while(n%P[i] == 0)
            n/=P[i], f[P[i]]++;
    }

    if(n!=1) f[n]++;
    return f;
}
void fast() {
    ll n; cin >> n;
    multiset<ll> v;
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        v.insert(x);
    }

    map<ll,ll> tar = PF(*v.begin());
    bool cool{true};
    for(auto num:v) {
        map<ll,ll> cur = PF(num);
        for(auto p:cur) {
            if(p.F==2) continue;
            if(tar[p.F] != p.S) cool=false;
        }
    }

    if(!cool) cout << -1;
    else {
        ll ans{};
        while(v.size()>1) {
            ll first = *v.begin();
            ll second = *next(v.begin());
            while(first<second) {
                v.erase(first);
                first *= 2;
                v.insert(first);
                ans++;

                first = *v.begin();
                second = *next(v.begin());
            }
            v.erase(v.begin()), v.erase(v.begin());
            v.insert(first*2);
        }
        cout << ans;
    }
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
