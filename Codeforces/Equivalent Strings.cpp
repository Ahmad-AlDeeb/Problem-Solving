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
const ll N = 2000;
const ll M = 998244353;
const ll MAX = 60 + 1;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}

ll big_pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans = ((ans % M) * (x % M)) % M;
        x = ((x % M) * (x % M)) % M;
        y /= 2;
    }
    return ans;
}

bool is_int(ld num) {
    return num == (ll) num;
}

int cmp_d(ld a, ld b) {
    if (fabs(a - b) <= EPS) return -1;
    return a > b ? 1 : 0;
}

ll mod(ll x, ll m) {
    return (x % m + m) % m;
}
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
string s1, s2;

bool isStringsEqual(int l1, int r1, int l2, int r2) {
    // Wihout Splitting
    bool isEqual{true};
    for(int i{l1}, j{l2}; i <= r1; ++i, ++j)
        if(s1[i] != s2[j])
                isEqual = false;
    if(isEqual) return true;


    // With Splitting
    int size = r1 - l1 + 1;
    if(size & 1) {
        return false;
    }

    int mid1 = (l1 + r1) / 2 + 1;
    int mid2 = (l2 + r2) / 2 + 1;

    return ( isStringsEqual(l1, mid1 - 1, l2, mid2 - 1) && isStringsEqual(mid1, r1, mid2, r2)     )
        || ( isStringsEqual(l1, mid1 - 1, mid2, r2)     && isStringsEqual(mid1, r1, l2, mid2 - 1) );
}

void fast() {
    cin >> s1 >> s2;
    if(isStringsEqual(0, s1.size() - 1, 0, s2.size() - 1)) {
        cout << "YES";
    }
    else cout << "NO";
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() {
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    // cin >> tc;
    for (ll i{1}; i <= tc; i++) {
        // cout << "Case " << i << ": ";

        fast();

        cout << endl;
        // if (i != tc) cout << endl;
    }
}
