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
void fast() {
    ll n; string s; cin >> n >> s;
    map<char,ll> f;
    for(auto c:s) f[c]++;
    ll tar{n/3};

    if(f['0']<tar) {
        for(auto &c:s) {
            if(f[c]>tar) f[c]--,c='0',f[c]++;
            if(f['0']==tar) break;
        }
    }
    if(f['2']<tar) {
        for(ll i{n-1}; i>=0; i--) {
            if(f[s[i]]>tar) f[s[i]]--,s[i]='2',f[s[i]]++;
            if(f['2']==tar) break;
        }
    }
    if(f['1']<tar) {
        for(auto &c:s)
            if(c=='2') {
                if(f['2']==tar) break;
                else f[c]--,c='1';
            }
        for(ll i{n-1}; i>=0; i--)
            if(s[i]=='0') {
                if(f['0']==tar) break;
                else f[s[i]]--,s[i]='1';
            }
    }
    cout << s;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
