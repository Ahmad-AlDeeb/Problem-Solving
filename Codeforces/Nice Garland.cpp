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
const ll N = 10000007;
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
string output; ll ans{MAX};
void get_ans(char c1, char c2, char c3, string s) {
    vector<char> color{c1,c2,c3};

    ll cnt{};
    for(ll i{},c{}; i<s.size(); i++,c++,c%=3)
        if(s[i] != color[c]) s[i]=color[c], cnt++;
    if(cnt < ans) output=s, ans=cnt;
}
void fast() {
    ll n; string s; cin >> n >> s;
    vector<char> color{'R','G','B'};

    for(ll i{}; i<3; i++)
        for(ll j{}; j<3; j++)
            for(ll k{}; k<3; k++)
                if(i!=j && j!=k && i!=k)
                    get_ans(color[i],color[j],color[k], s);
    cout << ans << endl << output;
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
