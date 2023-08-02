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
map<ll,ll> val;
map<ll,ll> ans;
void ini() {
    for(ll i{}; i<=999999; i++) {
        string s = to_string(i);
        ll sz = s.size();

        if(sz<6) {
            ll zeros {6-sz};
            string add;
            while(zeros--) add+='0';
            add += s;
            s = add;
        }

        ll l = (s[0]-'0')+(s[1]-'0')+(s[2]-'0');
        ll r = (s[3]-'0')+(s[4]-'0')+(s[5]-'0');
        ll diff = abs(r-l);
        val[diff]++;

        ll cnt{};
        for(auto d:val) if(d.F<diff) cnt+=d.S;
        ans[i]=cnt;
    }
}
void fast() {
    ll n; cin >> n;
    while(n--) {
        ll ticket; cin >> ticket;
        cout << ans[ticket] << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ini();
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
