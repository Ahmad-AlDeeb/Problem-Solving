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
void fast() {
    ll n,m; cin >>n>>m;
    ll mn{MAX}; vll mini;

    /// Reading elements + getting minimum index
    vll v(n);
    for(ll i{}; i<n; i++) {
        cin >> v[i];
         mini.pb(i+1);
    }
    /// Reading segments
    vector<pair<ll,ll>> seg(m);
    for(auto &i:seg) cin >> i.F >> i.S;


    bool equal{true};
    for(auto num:v) if(num!=v.front()) equal=false;

    ll diff{-MAX}; vll subset;
    /// Trying solution for every different minimum
    if(!equal) {
        for(auto p:mini) {
            vll v2(v); vll chosen_seg;

            for(ll i{}; i<seg.size(); i++)
                if(p>=seg[i].F && p<=seg[i].S) {
                    chosen_seg.pb(i+1);
                    for(ll j{seg[i].F}; j<=seg[i].S; j++)
                        v2[j-1]--;
                }
            ll d = *max_element(all(v2)) - *min_element(all(v2));
            if(d > diff)
                diff=d, subset=chosen_seg;
        }
    }
    else { /// All elements are equal
        for(auto p:mini) {
            vll v2(v); vll chosen_seg;

            for(ll i{}; i<seg.size(); i++)
                if(p<seg[i].F || p>seg[i].S) {
                    chosen_seg.pb(i+1);
                    for(ll j{seg[i].F}; j<=seg[i].S; j++)
                        v2[j-1]--;
                }
            ll d = *max_element(all(v2)) - *min_element(all(v2));
            if(d > diff)
                diff=d, subset=chosen_seg;
        }
    }



    cout << diff << endl;
    cout << subset.size() << endl;
    for(auto i:subset) cout << i << " ";
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
