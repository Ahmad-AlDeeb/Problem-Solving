#include<iostream>
#include <cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<sstream>
#include<limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll unsigned long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define vll vector<long long>
const ll inf = 1e18;
const ll M = 1e9+7;
const ll SZ = 200005;
vll di {0,0,1,-1};
vll dj {1,-1,0,0};
string letters{"abcdefghijklmnopqrstuvwxyz"};
const ld PI = 3.14159265358979323846;

bool is_int(ld double_num) {
    ll int_num = double_num;
    return int_num == double_num;
}
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
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
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

ld dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
pair<ld,ld> quad(ld a, ld b, ld c) {
    ld sq = sqrt(pow(b,2LL)-4*a*c);
    return {-b+(sq)/2*a, -b-(sq)/2*a};
}
void coordinate_compress(vll &axis, ll start=2, ll step=2) {
    set<ll> s (axis.begin(), axis.end());
    map<ll,ll> index;

    ll i{};
    for(auto val:s)
        index[val] = start + (step * i++);

    for(auto &val:axis)
        val = index[val];
}
void coordinate_compress(vll &axis, vll &values, map<ll,ll> &index, ll start=2, ll step=2) {
    for(auto &val:axis)
        index[val] = 0;
    values.resize(start + step*axis.size());

    ll i{};
    for(auto &p:index) {
        p.S = start + (step * i++);
        values[p.S] = p.F;
    }

    for(auto &val:axis)
        val = index[val];
}

ll SS;
bitset<100000010> BS;
vll P;
void sieve(ll sz) { // (1e7 < 1s) <-- O(n loglogn)
    SS = sz+1;
    BS.set(); BS[0]= BS[1]=false;

    for(ll i{2}; i<SS; ++i) if(BS[i]) {
            for(ll j{i*i}; j<SS; j+=i)
                BS[j]=false;
            P.pb(i);
        }
}
bool prime(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    if(n < SS) return BS[n];
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i)
        if(n%P[i] == 0) return false;
    return true;
}
vll PF(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    vll factors;
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        while(n%P[i] == 0)
            n/=P[i], factors.pb(P[i]);
    }

    if(n!=1) factors.pb(n);
    return factors;
}
vll PF() {
    vll PF_cnt(10000007);
    for(ll i{2}; i<=PF_cnt.size(); ++i)
        if(!PF_cnt[i]) // if true then i is prime
            for(ll j{i}; j<=PF_cnt.size(); j+=i)
                ++PF_cnt[j];
    return PF_cnt;
}
vll div(ll x) {
    vll div;
    for(ll i{1}; i*i<=x; i++)
        if(x%i == 0) {
            div.pb(i);
            if(i*i != x) div.pb(x/i);
        }
    return div;
}
ll div_cnt(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll cnt{1};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        ll power{};
        while(n%P[i] == 0) n/=P[i], ++power;
        cnt *= power+1;
    }
    return (n!=1)? 2*cnt:cnt;
}
//ll div_sum(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
//    ll sum{1};
//    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
//        ll multi{P[i]}, total{1};
//        while(n%P[i] == 0) n/=P[i], total+=multi, multi*=P[i];
//        sum *= total;
//    }
//
//    if(n!=1) sum *= (n+1); // N^2-1/N-1 = N+1
//    return sum;
//}
vector<vll> multi(ll x) { // 2*1e6
    vector<vll> multi(x+1);
    for(ll div{}; div<=x; div++)
        for(ll i{div}; i<=x; i+=div)
            multi[i].pb(div);
    return multi;
}
ll euler(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll co{n};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        if(n%P[i] == 0) co -= co / P[i];
        while(n%P[i] == 0) n/=P[i];
    }

    if(n!=1) co -= co/n;
    return co;
}
vll euler() {
    vll co(10000007);
    for(ll i{1}; i<co.size(); ++i)
        co[i]=i;
    for(ll i{2}; i<co.size(); ++i)
        if(co[i]==i) // if  true then i is prime
            for(ll j{i}; j<=co.size(); j+=i)
                co[j] = (co[j]/i) * (i-1);
    return co;
}

ll PP_fact(ll n, ll p) {
    ll exp{};
    for(ll i{p}; i<=n; i*=p)
        if(i>0) exp += n/i;
    return exp;
}
ll fact(ll n) {
    if(n <= 1) return 1;
    return (n * fact(n-1));
}
ll perm(ll n, ll r) {
    ll ans{1};
    for(ll i{n-r+1}; i<=n; i++) {
        ans *= i;
        ans %= M;
    }
    return ans;
}
ll comb(ll n, ll r) {
    ll ans{1}, div{1};
    for(ll i{r+1}; i<=n; i++) {
        ans *= i;
        ans /= div;
        div++;
    }
    return ans;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll zeros(ll num) {
    return num/5+1;
}
void fast() {
    ll l,r;
    while(cin >> l >> r) {
        if(!l && !r) break;
        cout << (zeros(r)+1) - zeros(l) << endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
//     cin >> tc;
    while(tc--) {
        fast();
//         cout << endl;
    }
//    while(true) {
////        ll n = 2601;
//        ll n = rand()%10+1;
//        if(fast(n) == slow(n)) cout << n << " OK!\n";
//        else {
//            cout << "NOT MATCHED!\n";
//            cout << n << endl << slow(n) << " " << fast(n);
//            break;
//        }
//    }
}
