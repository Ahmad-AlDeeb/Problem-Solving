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
    ll n,k; cin >> n >> k;

    if(k!=4) {
        ll ans{MAX};
        for(ll i{}; i<n; i++) {
            ll x; cin >> x;
            if(x%k == 0) ans=0;

            ll cost {k - (x%k)};
            ans = min(ans, cost);
        }
        cout << ans;
    }
    else {
        vll twos,fours;
        for(ll i{}; i<n; i++) {
            ll x; cin >> x;
            if(x%4 == 0) fours.pb(0);
            else {
                ll cost {4 - (x%4)};
                fours.pb(cost);
            }

            if(x%2 == 0) twos.pb(0);
            else {
                ll cost {2 - (x%2)};
                twos.pb(cost);
            }
        }
        sort(all(twos));
        sort(all(fours));
        cout << min(fours.front(), twos[0]+twos[1]);
    }
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
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
