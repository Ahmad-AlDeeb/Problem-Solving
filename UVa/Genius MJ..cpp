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

/////////////////////////// MACROS ///////////////////////////
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define ordered_set tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>

/// CONST variables ///
const ll inf = 1e18;
const ll M = 1e9+7;
const ll SZ = 200005;
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-20;

///////// MISC /////////
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
bool is_int(ld double_num) {
    ll int_num = double_num;
    return int_num == double_num;
}
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
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

////// Prime & Factorization //////
ll SS; vll P; bitset<100000010> BS;
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
ll div_sum(ll n) { // 1e13 ==> (work for N <= (last prime in vll P)^2)
    ll sum{1};
    for(ll i{}; i<P.size() and P[i]*P[i]<=n; ++i) {
        ll multi{P[i]}, total{1};
        while(n%P[i] == 0)
            n/=P[i], total+=multi, multi*=P[i];
        sum *= total;
    }

    if(n!=1) sum *= (n+1); // N^2-1/N-1 = N+1
    return sum;
}
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

///////// Factorial /////////
ll PP_fact(ll n, ll p) { // Legendre's formula
    ll exp{};
    for(ll i{p}; i<=n; i*=p)
        exp += n/i;
    return exp;
}
ll fact(ll n) {
    if(n <= 1) return 1;
    return (n * fact(n-1));
}
ll perm(ll n, ll r) {
    ll ans{1};
    for(ll i{n}; i>=n-r+1; i--) {
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

///// GCD + LCM + Euclid + Mod Inverse /////
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}
ll extEuclid(ll a, ll b, ll &x, ll &y) {
    ll x2 = y = 0;
    ll y2  = x = 1;
    while(b) {
        ll q {a/b};

        ll temp{b};
        b = a%b;
        a = temp;

        temp = x2;
        x2 = x-(q*x2);
        x = temp;

        temp = y2;
        y2 = y-(q*y2);
        y = temp;
    }
    return a; // a here = d = gcd(a,b)
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
ll mod_inverse(ll b, ll m) { // returns [ b^(-1) % m ] if possible
    ll x,y;
    ll d = extEuclid(b,m,x,y); // to get [ b*x + m*y = d ]
    if(d != 1) return -1; // to indicate failure

    return mod(x,m);
}

///// Geometry /////
struct point {
    ld x,y;
    point() {x=y=0.0;}
    point(ld x, ld y) : x(x), y(y) {}

    bool operator< (point other) const {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(const point &other) const {
        return (fabs(x-other.x)<EPS) and (fabs(y-other.y)<EPS);
    }
};
ld dist(const point &p1, const point &p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
ld deg_to_rad(ld d) {
    return d*M_PI / 180.0;
}
ld rad_to_deg(ld r) {
    return r*180.0 / M_PI;
}
point rotate(const point &p, ld theta) {
    ld rad = deg_to_rad(theta);
    return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
struct point2 {
    ll x,y;
    point2() {x=y=0;}
    point2(ll x, ll y, ll z) : x(x), y(y){}
};
ld dist2(const point2 &p1, const point2 &p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
void fast() {
    ll n; cin >> n;
    vector<point2> p1(n),p2(n);
    for(auto &i:p1) cin >> i.x >> i.y;
    for(auto &i:p2) cin >> i.x >> i.y;

    vector<ld>d1;
    point2 pin = p1.front();
    for(auto p:p1)
        d1.pb(dist2(pin,p));
    sort(all(d1));

    vector<ld>d2;
    for(auto p21:p2) {
        for(auto p22:p2) {
            ld d = dist2(p21,p22);
            if(binary_search(all(d1),d)) d2.pb(d);
            else {d2.clear(); break;}
        }
        if(!d2.empty()) break;
    }
    sort(all(d2));

    if(d1 == d2) cout << "MATCHED"; else cout << "NOT MATCHED";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
     cin >> tc;
    while(tc--) {
        fast();
         cout << endl;
    }

    ///////////////// Stress testing /////////////////
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
