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
ll x,y,a1,a2,b1,b2;
ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt( pow(abs(x1-x2),2LL) + pow(abs(y1-y2),2LL) );
}
bool valid(ld w) {
    bool start{false}, home{false}, connected{false};

    if(distance(0,0,a1,a2)<=w or distance(0,0,b1,b2)<=w)
        start=true;
    if(distance(x,y,a1,a2)<=w or distance(x,y,b1,b2)<=w)
        home=true;
    if(distance(a1,a2,b1,b2) <= 2.0*w)
        connected=true;

    bool success_with_both = (start and home and connected);
    bool success_with_a = (distance(0,0,a1,a2)<=w and distance(x,y,a1,a2)<=w);
    bool success_with_b = (distance(0,0,b1,b2)<=w and distance(x,y,b1,b2)<=w);

    return success_with_both or success_with_a or success_with_b;
}
void fast() {
    cin>>x>>y>>a1>>a2>>b1>>b2;
    if(!x and !y) {cout << 0; return;}

    ld l{0.0}, r{10000.0};
    while(fabs(r-l) > 10e-7) {
        ld mid {(l+r)/2.0};
        if(valid(mid)) r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(10) << r;
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
