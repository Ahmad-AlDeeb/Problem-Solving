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
const ll N = 1e7+7;
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
    vll v(n); for(auto &i:v) cin >> i, f[i]++;

    ll tar1{}, tar2{};
    for(auto p:f) if(p.S >= 2) {tar1=p.F; break;}
    for(auto p:f) if(p.S >= 2 and p.F!=tar1) {tar2=p.F; break;}

    if(!tar1 or !tar2 or f.size()<2) cout << -1;
    else {
        bool one{true}, two{true};

        for(auto num:v) {
            if(num==tar1) {
                if(one) cout << 1 << " ";
                else    cout << 2 << " ";
                one=!one;
            }
            else if(num==tar2) {
                if(two) cout << 2 << " ";
                else    cout << 3 << " ";
                two=!two;
            }
            else cout << 1 << " "; // any 1,2,3
        }
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
