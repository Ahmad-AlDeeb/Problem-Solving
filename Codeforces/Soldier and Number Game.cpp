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
const ll N {5000006};
const ll M = 998244353;
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
ll SS; bitset<100000010> BS;
vll sieve(ll sz) { // (1e7 < 1s) <-- O(n loglogn)
    vll cnt(sz);
    SS = sz+1;
    BS.set(); BS[0]= BS[1]=false;

    for(ll i{2}; i<SS; ++i) if(BS[i]) {
            for(ll j{i}; j<SS; j+=i) {
                BS[j]=false;
                ll tmp {j};
                while(tmp%i == 0)
                    cnt[j]++, tmp/=i;
            }
        }
    return cnt;
}
void fast(vll &cnt) {
    ll a,b; cin>>a>>b;
    cout << cnt[a]-cnt[b];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    vll cnt = sieve(N);
    for(ll i{1}; i<N; i++) cnt[i]+=cnt[i-1];

    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast(cnt);
        cout << endl;
    }
}
