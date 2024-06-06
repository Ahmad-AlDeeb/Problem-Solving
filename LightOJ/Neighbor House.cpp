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
int mini{20000};

void rec(vector<vector<int>> &h, int i, int c, int cost) {
    if(cost >= mini || i == h.size())
        return;
    if(i == h.size()-1) {
        mini = cost;
        return;
    }

    int c1 = (c+1) % 3;
    int c2 = (c+2) % 3;

    rec(h, i+1, c1, cost + h[i+1][c1]);
    rec(h, i+1, c2, cost + h[i+1][c2]);
}


void fast() {
    mini = 20000;

    int n; cin >> n;
    vector<vector<int>> houses (n, vector<int>(3));
    for(int i{}; i<n; i++)
        for(int c{}; c<3; c++)
            cin >> houses[i][c];

    rec(houses, 0, 0, houses[0][0]);
    rec(houses, 0, 1, houses[0][1]);
    rec(houses, 0, 2, houses[0][2]);

    cout << mini;
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }
}
