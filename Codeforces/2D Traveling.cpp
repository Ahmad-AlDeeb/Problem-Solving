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
const ll N = 1e4+4;
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
    ll n,k,a,b; cin >> n >> k >> a >> b;
    vector<pair<ll,ll>> v(n);
    for(ll i{}; i<n; i++) cin >> v[i].F >> v[i].S;

    ll major{MAX};
    for(ll i{}; i<k; i++)
        major = min(major, abs(v[b-1].F-v[i].F) + abs(v[b-1].S-v[i].S));

    ll major2{MAX};
    for(ll i{}; i<k; i++)
        major2 = min(major2, abs(v[a-1].F-v[i].F) + abs(v[a-1].S-v[i].S));


    if(a<=k && b<=k) cout << 0;
    else if(a<=k) cout << major;
    else if(b<=k) cout << major2;
    else {

        cout << min(major+major2, abs(v[b-1].F-v[a-1].F) + abs(v[b-1].S-v[a-1].S));
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
