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
const ll N = 31;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS {1e-19};
const ld PI {3.14159265358979323846};
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
    ll n; cin >> n;
    vll v(n-1); for(auto &i:v) cin >> i;
    vll d(n-1); d.front()=v.front();


    vll miss;

    set<ll>s;
    for(ll i{1}; i<=n; i++) s.insert(i);
    if(s.count(v.front())) s.erase(v.front());
    else miss.pb(v.front());


    for(ll i{1}; i<n-1; i++) {
        d[i] = v[i]-v[i-1];

        if(s.count(d[i])) s.erase(d[i]);
        else miss.pb(d[i]); // we meet only one ???
    }

//    cout << miss.size() << " ";
    if(s.size()==1) cout << "YES";
    else if(s.size()==2) {
        ll sum{};
        for(auto num:s) sum+=num;
        if(sum == miss.front()) cout << "YES";
        else            cout << "NO";
    } else cout << "NO";
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
