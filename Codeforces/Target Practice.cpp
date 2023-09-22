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
const ll N = 1e5+1;
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
ll get_score(vector<vector<char>> &g, ll lvl, ll d) {
    ll score{};
    for(ll j{d}; j<10-d; j++) {
        if(g[d][j]=='X') score += 6-lvl;
        if(g[9-d][j]=='X') score += 6-lvl;
    }
    for(ll i{1+d}; i<9-d; i++) {
        if(g[i][d]=='X') score += 6-lvl;
        if(g[i][9-d]=='X') score += 6-lvl;
    }
    return score;
}
void fast() {
    vector<vector<char>> g(10,vector<char>(10));
    for(ll i{}; i<10; i++)
        for(ll j{}; j<10; j++) cin >> g[i][j];

    ll score{};
    for(ll i{5},d{0}; i>=0; i--,d++)
        score += get_score(g, i,d);
    cout << score;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
