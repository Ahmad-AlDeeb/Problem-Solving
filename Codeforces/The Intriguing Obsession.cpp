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
const ll N = 500005;
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
ll mod_pow(ll b, ll p, ll m) {
    if(!p) return 1;

    ll ans = mod_pow(b,p/2,m);
    ans = mod(ans*ans,m);

    if(p&1) ans = mod(ans*b,m);
    return ans;
}
// M is a prime number > N
ll inv(ll a) {     // Fermat's little theorem
    return mod_pow(a,M-2,M); // O(log p)
}
ll Fact[N];
void ini_fact() { // O(n)
    Fact[0]=1;
    for(ll i{1}; i<N; i++)
        Fact[i] = (Fact[i-1]*i) % M;
}
ll C(ll n, ll k) {
    if(n<k) return 0;
    return ( ((Fact[n] * inv(Fact[k]))%M) * inv(Fact[n-k]) ) % M;
}
ll ways(ll a, ll b) {
    ll k = min(a,b);
    ll ans{};
    for(ll i{}; i<=k; i++)
        ans += ( ((C(a,i)*C(b,i))%M) * Fact[i])%M, ans%=M;
    return ans;
}
void fast() {
    ll a,b,c; cin>>a>>b>>c;
    cout << ( ((ways(a,b) * ways(b,c))%M) * ways(a,c))%M;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ini_fact();
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
