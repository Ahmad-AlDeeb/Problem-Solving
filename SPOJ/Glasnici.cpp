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
ld k; ll n;
bool valid(vector<ld> pos, ld sec) {
    ld last_pos = pos.front() + sec;

    for(int i{1}; i < n; ++i) {
        ld last_pos_msg = last_pos + k;

        if(pos[i] - sec > last_pos_msg)
            return false;

        last_pos = min(last_pos_msg, pos[i] + sec);
    }

    return true;
}
void fast() {
    cin >> k >> n;
    vector<ld> messengers(n);
    for(auto &messenger : messengers) {
        cin >> messenger;
    }

    ld l{0.0}, r{1000000000};
    for(int iter{}; iter < 100; ++iter) {
        ld mid = (l + r) / 2;
        if(valid(messengers, mid)) {
            r = mid;
        }
        else {
            l = mid;
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


