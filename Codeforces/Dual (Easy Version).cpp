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
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void print(vector<pair<ll,ll>> &v) {
    cout << v.size() << endl;
    for(ll i{}; i<v.size(); i++) {
        cout << v[i].F+1 << " " << v[i].S+1;
        if(i!=v.size()-1) cout << endl;
    }
}
void fast() {
    ll n; cin >> n;
    pair<ll,ll> mx(-1,-21),mn(-1,21);

    vll v(n);
    for(ll i{}; i<n; i++) {
        cin >> v[i];

        if(v[i]!=0) {
            if(v[i] > mx.S)
                mx.F=i, mx.S=v[i];
            if(v[i] < mn.S)
                mn.F=i, mn.S=v[i];
        }
    }


    vll v2(v);
    vector<pair<ll,ll>> ans;
    for(ll i{1}; i<n; i++)
        while(v2[i-1] > v2[i]) {
            v2[i] += mx.S;
            ans.emplace_back(i,mx.F);
            if(ans.size()>50) goto out;

            if(v2[i] > mx.S)
                mx.F=i, mx.S=v2[i];
        }
    out:

    if(ans.size()<=50) print(ans);
    else { // sure?
        ans.clear();
        for(ll i{n-2}; i>=0; i--)
            while(v[i] > v[i+1]) {
                v[i] += mn.S;
                ans.emplace_back(i,mn.F);


                if(v[i] < mn.S)
                    mn.F=i, mn.S=v[i];
            }
        print(ans);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
        cout << endl;
    }
}
