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
const ll N = 1e5+1;
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
bool valid(ll l, ll r, ll tar, vector<vll> &pre) {
    ll res{};
    for(ll bit{}; bit<32; bit++) {
        if(l) {
            if(pre[r][bit] - pre[l-1][bit] == r-l+1)
                res += pow(2LL, bit);
        }
        else {
            if(pre[r][bit] == r + 1)
                res += pow(2LL, bit);
        }
    }
    return res >= tar;
}
void fast() {
    ll n; cin >> n;
    vll v(n); for(auto &i:v) cin >> i;

    // Converting numbers into strings then into vector of digits of ones and zeors
    vector<vll> pre;
    for(ll i{}; i<n; i++) {
        vll number;
        string s = bitset<32>(v[i]).to_string();
        for(auto c:s)
            if(c=='0') number.pb(0); else number.pb(1);
        reverse(all(number));
        pre.pb(number);
    }

    // Making prefix sum of zeros and ones
    for(ll j{}; j<32; j++)
        for(ll i{1}; i<n; i++)
            pre[i][j] += pre[i-1][j];

    // reading queries
    ll q; cin >> q;
    while(q--) {
        ll left,k; cin >> left >> k; left--;
        if(v[left] < k) {cout << -1 << " "; continue;}

        ll l{left}, r{n-1}, ans;
        while(l<=r) {
            ll mid {l+(r-l)/2};
            if(valid(left, mid, k, pre))
                 l=mid+1, ans = mid;
            else r=mid-1;
        }
        cout << ans+1 << " ";
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
