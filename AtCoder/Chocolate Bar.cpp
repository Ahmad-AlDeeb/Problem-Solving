#include <bits/stdc++.h>
#include <cctype>
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
ll calc2(ll a, ll b, ll area1) {
    ll area2 = a*(b/2);
    ll area3 {area2};
    if(b&1) area3 = a*(b/2+1);
    return max({area1,area2,area3}) - min({area1,area2,area3});
}
ll calc(ll a, ll b) {
    ll a1 = a/3;
    ll rem = a%3;
    if(rem==2) a1++;
    ll area1 = a1*b;
    a -= a1;
    return min(calc2(a,b,area1),calc2(b,a,area1));
}
void fast() {
    ll h,w; cin >> h >> w;
    if(h%3==0 or w%3==0) cout << 0;
    else cout << min(calc(h,w),calc(w,h));
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

