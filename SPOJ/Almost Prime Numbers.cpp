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
//            r,l,u,d
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {10004};
const ld PI = 3.14159265358979323846;
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
vector<vll> multi(10004);
void fast() {
    ll n,k; cin >> n >> k;
    vll v(k); for(auto &i:v) cin >> i;

    ll ans{};
    for(ll i{1}; i<=n; i++) {
        bool cool{true};
        for(auto p:v)
            if(binary_search(all(multi[i]),p))
                cool=false;
        if(cool && multi[i].size()>2) ans++;
    }
    cout << ans;
}
void ini() {
    for(ll div{1}; div<10004; div++)
        for(ll i{div}; i<10004; i+=div)
            multi[i].pb(div);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ini();
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }
}
