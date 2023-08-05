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
const ll N = 11;
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
ll tar;
bool valid(ll x, ll y, vll v) {
    map<ll,ll>f;
    for(auto &i:v) {
        if(i<tar) {
            ll moves = min(tar-i, x);
            x -= moves;
            i+=moves;
            f[i]++;
        }
        else if(i>tar+1) {
            ll moves = min(i-tar-1, y);
            y -= moves;
            i-=moves;
            f[i]++;
        }
    }
    return f.size()==2;
}
void fast() {
    ll n; cin >> n;
    ll s{};
    vll v(n); for(auto &i:v) cin >> i, s+=i;
    sort(all(v));
    tar = s/n;

    ll l{},r{1000000000000000000}, ans{};
    while(l<=r) {
        ll mid {l+(r-l)/2};
        if(valid(mid,mid,v)) r=mid-1, ans=mid;
        else           l=mid+1;
    }
    cout << ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
