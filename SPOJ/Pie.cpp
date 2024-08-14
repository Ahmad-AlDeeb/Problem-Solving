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
const ld PI = 3.14159265358979323846;
bool valid(vector<ld>& volumes, int friends, ld volume) {
    int count{};
    for(auto vol : volumes) {
        count += floor(vol / volume);
    }
    return count >= friends;
}
void fast() {
    ll n,f; cin >> n >> f; f++;

    vector<ld> volumes;
    ld max_volume{0.0};
    for(int i{}; i<n; i++) {
        ld x; cin >> x;
        volumes.pb(x * x * PI);
        max_volume = max(max_volume, volumes.back());
    }

    ld l{0.0}, r{max_volume};
    for(int iter{}; iter<100; ++iter) {
        ld mid = (l + r) / 2;
        if(valid(volumes, f, mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << fixed << setprecision(4) << l;
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


