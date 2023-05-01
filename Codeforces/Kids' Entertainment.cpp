#include<iostream>
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
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
const ll SZ = 5005;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};
string letters{" abcdefghijklmnopqrstuvwxyz"};

ll power(ll x, ll y) {
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
    return a*b / gcd(a,b);
}
ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
vector<ll> p_fact(ll x) {
    ll i{2}; vector<ll> p;
    for(; i*i <= x; i++) {
        if(x%i == 0) p.pb(i);
        while(x%i == 0) x /= i;
    }
    if(x != 1) p.push_back(x);
    return p;
}
bool is_int(dd double_num) {
    int int_num = double_num; // narrow double by copying to int
    if(int_num == double_num) // if the number is int then they must be equal but if not equal then the num was double
        return true;
    return false;
}
bool is_prime(ll x) {
    for(ll i{2}; i*i<=x; i++)
        if(x%i == 0) return false;
    return true;
}
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}
vector<ll> sieve(ll n) {
    vector<bool>primes(n+1,true);
    for(ll i{2}; i*i<=n; i++)
        if(primes[i])
            for(ll j{i*i}; j<=n; j+=i)
                primes[j]=false;

    vector<ll>ans;
    for(ll i{2}; i<=n; i++)
        if(primes[i]) ans.pb(i);
    return ans;
}
/////////////////////////////////////////////////////////////////////////////////////
vector<pair<ll,pair<bool,bool>>>picks
{{6, make_pair(1,1)}, {2, make_pair(1,1)}, {5, make_pair(1,0)}, {5, make_pair(1,1)}, {4, make_pair(1,1)},
 {5, make_pair(0,1)}, {6, make_pair(0,1)}, {3, make_pair(1,1)}, {7, make_pair(1,1)}, {6, make_pair(1,1)}};
vector<pair<bool,bool>>lefts
{make_pair(1,1),make_pair(0,0),make_pair(0,1),make_pair(0,0),make_pair(1,0),
 make_pair(1,0),make_pair(1,1),make_pair(0,0),make_pair(1,1),make_pair(1,0)};
ll maxi{99999999};
void fast() {
    string s; cin >> s;
    if(s=="100") cout << 12;
    else {
        ll ans{};
        ll x = s.front()-'0';
        ll y = s.back()-'0';
        ans += picks[x].F+picks[y].F;
        if(x==1) {cout << ans; return;}

        pair<bool,bool> right = picks[x].S;
        pair<bool,bool> left = lefts[y];
        if(right.F == left.F && right.S == left.S) {
            if(right.F) ans--;
            if(right.S) ans--;
        }
        cout << ans;
    }
}


/////////////////////////////////////////////////////////////////////////////////////
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
}
