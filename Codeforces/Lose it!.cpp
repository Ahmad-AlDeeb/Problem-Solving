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
///////////////////////////////////////
const ll N = 1e5+1;
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
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
void fast() {
    ll n; cin >> n;
    map<ll,ll> f;
    ll ans{};
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        if(x == 4) f[4]++;

        if(x==8) {
            if(f[4]) f[8]++, f[4]--;
            else ans++;
        }
        if(x==15) {
            if(f[8]) f[15]++, f[8]--;
            else ans++;
        }
        if(x==16) {
            if(f[15]) f[16]++, f[15]--;
            else ans++;
        }
        if(x==23) {
            if(f[16]) f[23]++, f[16]--;
            else ans++;
        }
        if(x==42) {
            if(f[23]) f[42]++, f[23]--;
            else ans++;
        }
    }

    cout << ans + f[4] + 2*f[8] + 3*f[15] + 4*f[16] + 5*f[23];
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
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
