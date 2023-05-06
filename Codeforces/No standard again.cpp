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
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e18;
const ll M = 1e9+7;
const ll SZ = 200005;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};
string letters{" abcdefghijklmnopqrstuvwxyz"};

ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%inf)*(x%inf)) % inf;
        x = ((x%inf) * (x%inf)) %inf;
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
void coordinate_compress(vector<ll>&axis, ll start=2, ll step=2) {
    set<ll> s (axis.begin(), axis.end());
    map<ll,ll> index;

    ll i{};
    for(auto val:s)
        index[val] = start + (step * i++);

    for(auto &val:axis)
        val = index[val];
}
void coordinate_compress(vector<ll> &axis, vector<ll> &values, map<ll,ll> &index, ll start=2, ll step=2) {
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
/////////////////////////////////////////////////////////////////////////////////////

void fast() {
    ll n,q; cin >> n >> q;
    vector<ll>x(n+q*2+1),y(n+q*2+1),v(n);
    for(ll i{}; i<n; i++)
        cin >> x[i] >> y[i] >> v[i];
    vector<ll>point_x(x);
    vector<ll>point_y(y);

    vector<pair<pair<ll,ll>,pair<ll,ll>>> queries(q);
    for(ll i{},j{n}; i<q; i++,j++) {
        cin >> queries[i].F.F >> queries[i].F.S >> queries[i].S.F >> queries[i].S.S;
        x[j] = queries[i].F.F;
        y[j] = queries[i].F.S;
        j++;
        x[j] = queries[i].S.F;
        y[j] = queries[i].S.S;
    }

    vector<ll>values_x; map<ll,ll>index_x;
    coordinate_compress(x, values_x, index_x, 1,1);
    vector<ll>values_y; map<ll,ll>index_y;
    coordinate_compress(y, values_y, index_y, 1,1);

    vector<vector<ll>>grid(2002,vector<ll>(2002));
    for(ll i{}; i<n; i++)
        grid[index_x[point_x[i]]][index_y[point_y[i]]] = v[i];
    for(ll i{2}; i<2002; i++) grid[i][1] += grid[i-1][1];
    for(ll j{2}; j<2002; j++) grid[1][j] += grid[1][j-1];
    for(ll i{1}; i<2002; i++)
        for(ll j{1}; j<2002; j++)
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];


    for(ll i{}; i<q; i++) {
        ll top_x = index_x[queries[i].F.F];
        ll top_y = index_y[queries[i].F.S];
        ll down_x = index_x[queries[i].S.F];
        ll down_y = index_y[queries[i].S.S];

        ll a = grid[down_x][down_y];
        ll b = grid[down_x][top_y-1];
        ll c = grid[top_x-1][down_y];
        ll d = grid[top_x-1][top_y-1];
        cout << a -b -c +d << endl;
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
