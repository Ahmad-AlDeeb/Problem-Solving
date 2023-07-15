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
void fast() {
    ll w,h,n; cin >> w >> h >> n;
    map<ll,ll> f;
    f[1]=f[3]=0;
    f[2]=w; f[4]=h;

    for(ll i{}; i<n; i++) {
        ll x,y,a; cin >> x >> y >> a;

        if(a==1) f[1] = max(f[1],x);
        if(a==3) f[3] = max(f[3],y);

        if(a==2) f[2] = min(f[2],x);
        if(a==4) f[4] = min(f[4],y);
    }


    if(f[2]<=f[1] or f[4]<=f[3]) cout << 0;
    else {
        ll width = f[2]-f[1];
        ll height = f[4]-f[3];
        cout << width*height;
    }
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
