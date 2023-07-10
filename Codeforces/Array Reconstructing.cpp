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
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ld G_pos = (1+sqrt(5))/2;
const ld G_neg = (1-sqrt(5))/2;
const ll SZ {101};
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
ll fib(ll n) {
    return ( pow(G_pos,n) - pow(G_neg,n) ) / (ld)sqrt(5);
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    ll n,m; cin >> n >> m;
    vll v(n); for(auto &i:v) cin >> i;
    vll ans(n);

    ll loc;
    for(ll i{}; i<n; i++)
        if(v[i]!=-1) {loc=i; ans[i]=v[i]; break;}
    for(ll i{loc+1}; i<n; i++) {
        if(v[i]<0) v[i]=(v[i-1]+1)%m;
        ans[i] = v[i];
    }
    for(ll i{loc-1}; i>=0; i--) {
        if(v[i]<0) v[i]=mod((v[i+1]-1),m);
        ans[i] = v[i];
    }


    for(ll i{}; i<n; i++) {
        cout << ans[i];
        if(i!=n-1) cout << " ";
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    while(tc--) {
        fast();
        cout << endl;
    }
}
