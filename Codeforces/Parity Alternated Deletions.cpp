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
const ll N = 1e5+5;
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
const string letters{"abcdefghijklmnopqrstuvwxyz"};
void fast() {
    ll n; cin >> n;
    vll odds,evens;
    ll sum{};
    for(ll i{}; i<n; i++) {
        ll x; cin >> x; sum += x;

        if(x&1) odds.pb(x);
        else    evens.pb(x);
    }
    sort(all(odds),greater<>()), sort(all(evens),greater<>());

    if(abs((ll)odds.size()-(ll)evens.size()) <= 1) cout << 0;
    else {
        ll mn = min(odds.size(), evens.size());
        ll odd_s{}, even_s{};
        for(ll i{}; i<mn; i++) {
            odd_s += odds[i];
            even_s += evens[i];
        }

        ll extra;
        if(mn != odds.size()) extra = odds[mn];
        if(mn != evens.size()) extra = evens[mn];
        cout << sum - (odd_s+even_s+extra);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
