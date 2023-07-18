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
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
const ld PI = 3.14159265358979323846;
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
    ll k; cin >> k;
    vector< set<pair<ll,int>> > sequences;
    for(ll i{1}; i<=k; i++) {
        ll n; cin >> n;
        ll sum{};
        vll v(n); for(auto &j:v) cin >> j, sum+=j;

        map<ll,bool> exist;
        set<pair<ll,int>> seq;
        for(ll j{}; j<n; j++) {
            ll rem = sum-v[j];
            if(!exist[rem]) {
                seq.emplace(rem, j+1);
                exist[rem]=true;
            }
        }
        sequences.pb(seq);
    }

    // map<sum, vector<pair<seq,pos>>>
    map<ll, vector<pair<ll,ll>>> ans;
    for(ll i{}; i<k; i++)
        for(auto s:sequences[i])
            ans[s.F].emplace_back(i+1,s.S);

    for(auto p:ans)
        if(p.S.size()>=2) {
            auto s1 = p.S[0];
            auto s2 = p.S[1];
            cout << "YES\n";
            cout << s1.F << " " << s1.S << endl;
            cout << s2.F << " " << s2.S;
            return;
        }
    cout << "NO";
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
