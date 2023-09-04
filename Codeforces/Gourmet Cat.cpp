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
string two_weeks{"baabcacbaabcac"};
ll get_days(ll i, ll a, ll b, ll c) {
    ll days{};
    for(; i<14; i++) {
        if(two_weeks[i] == 'a' && !a) break;
        if(two_weeks[i] == 'a' && a) a--;

        if(two_weeks[i] == 'b' && !b) break;
        if(two_weeks[i] == 'b' && b) b--;

        if(two_weeks[i] == 'c' && !c) break;
        if(two_weeks[i] == 'c' && c) c--;

        days++;
    }
    return days;
}
void fast() {
    ll a,b,c; cin >> a >> b >> c;
    ll weeks{};
    if(a>=3 && b>=2 && c>=2) {
        ll cnt_a = a/3;
        ll cnt_b = b/2;
        ll cnt_c = c/2;
        ll cnt = min({cnt_a, cnt_b, cnt_c});

        a-=3*cnt, b-=2*cnt, c-=2*cnt;
        weeks = cnt;
    }


    ll ans{};
    for(ll i{}; i<=6; i++)
        ans = max(ans, get_days(i, a, b, c));
    cout << weeks*7 + ans;
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
