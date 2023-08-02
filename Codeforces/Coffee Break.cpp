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
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
void fast() {
    ll n,m,d; cin >>n>>m>>d;
    set<ll> s; map<ll,ll>f;
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        s.insert(x);
        f[x]=i;
    }

    ll ans{1}; vector<ll> ind(n);
    ll cur{*s.begin()};
    s.erase(cur); ind[f[cur]]=ans;

    while(!s.empty()) {

        ll nex = cur+d+1;
        auto it = s.lower_bound(nex);
        
        if(it!=s.end()) {
            cur = *it;
            ind[f[cur]]=ans;
            s.erase(it);
        }
        else {
            ans++;
            cur = *s.begin(); s.erase(cur);
            ind[f[cur]]=ans;
        }

    }
    cout << ans << endl;
    for(auto num:ind) cout << num << " ";
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
