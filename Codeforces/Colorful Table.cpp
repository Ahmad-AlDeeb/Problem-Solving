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
void fast() {
    ll n,k; cin >> n >> k;
    map<ll,bool> exist;
    vll v(n); for(auto &i:v) cin >> i, exist[i]=true;

    vll first_big(k+1, -1);
    for(ll i{}; i<n; i++) {
        if(first_big[v[i]] != -1) continue;

        for(ll j{v[i]}; j>=0 &&  first_big[j] == -1; j--)
            first_big[j]=i;
    }

    vll last_big(k+1, -1);
    for(ll i{n-1}; i>=0; i--) {
        if(last_big[v[i]] != -1) continue;

        for(ll j{v[i]}; j>=0 &&  last_big[j] == -1; j--)
            last_big[j]=i;
    }

    for(ll i{1}; i<=k; i++) {
        if(!exist[i]) cout << 0 << " "; // << endl;
        else {
            ll l {first_big[i]}, r{n-last_big[i]-1};
//            cout << l << "--> " << r << endl;
            cout << (n+n) - (l+r)*2 << " ";
        }
    }
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
