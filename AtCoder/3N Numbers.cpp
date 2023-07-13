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
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
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
ll pre_l[300005], pre_r[300005];
void fast() {
    ll n; cin >> n;
    ll m {3*n};
    
    multiset<ll> ms;
    vll v(m+1);
    for(ll i{1}; i<=m; i++) {
        cin >> v[i];
        if(i<=n) {
            pre_l[i] = pre_l[i-1] + v[i];
            ms.insert(v[i]);
        }
        else {
            pre_l[i] = pre_l[i-1];
            ll mn = *ms.begin();
            if(v[i] > mn) {
                pre_l[i] -= mn;
                ms.erase(ms.find(mn));

                pre_l[i] += v[i];
                ms.insert(v[i]);
            }
        }
    }


    ms.clear();
    for(ll i{m}; i>=1; --i) {
        if(i >= m-n+1) {
            pre_r[i] = pre_r[i+1]+v[i];
            ms.insert(v[i]);
        }
        else {
            pre_r[i] = pre_r[i+1];
            ll mx = *ms.rbegin();
            if(v[i] < mx) {
                pre_r[i] -= mx;
                ms.erase(ms.find(mx));

                pre_r[i] += v[i];
                ms.insert(v[i]);
            }
        }
    }

    ll ans {-MAX};
    for(ll i{n}; i<=m-n; i++)
        ans = max(ans, pre_l[i]-pre_r[i+1]);
    cout << ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
