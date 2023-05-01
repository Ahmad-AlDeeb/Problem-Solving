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
    int int_num = double_num;
    if(int_num == double_num)
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


void fast() {
    ll n,q; cin >> n >> q;
    vector<ll>vec(n+1);
    for(ll i{1}; i<vec.size(); i++) cin >> vec[i];

    vector<ll>prefix(n+1),bad(n+1);
    for(ll i{1}; i<prefix.size()-2; i++)
        if(vec[i] >= vec[i+1] && vec[i+1] >= vec[i+2])
            prefix[i]=bad[i]=1;

    for(ll i{1}; i<prefix.size(); i++) prefix[i] += prefix[i-1];


    while(q--) {
        ll l,r; cin >> l >> r;
        if(l==r) cout << 1;
        else {
            ll ans = r-l+1 - (prefix[r]-prefix[l-1]);
            if(bad[r]) ans++;
            if(bad[r-1]) ans++;
            cout << ans;
        }
        cout << endl;
    }

}


/////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
