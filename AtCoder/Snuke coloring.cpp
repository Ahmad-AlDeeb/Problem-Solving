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
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
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
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
ll h,w;
bool in_range(ll n, ll m) {
    if(n>0&&n<h-1 and m>0&&m<w-1) return true;
    return false;
}
void fast() {
    ll n; cin >> h >> w >> n;
    map<pair<ll,ll>,ll> cell;
    for(ll i{}; i<n; i++) {
        ll x,y; cin >> x >> y; x--,y--;
        for(ll j{-1}; j<=1; j++)
            for(ll k{-1}; k<=1; k++)
                cell[make_pair(x+j,y+k)]++;
    }

    vll ans(10);
    for(auto c:cell)
        if(in_range(c.F.F,c.F.S))
            ans[c.S]++;

    ans[0] = (h-2) * (w-2);
    for(ll i{1}; i<=9; i++)
        ans[0] -= ans[i];

    for(ll i{}; i<=9; i++)
        cout << ans[i] << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
