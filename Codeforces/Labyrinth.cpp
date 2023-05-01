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
ll maxi{99999999}; ll w;
void print(vector<vector<char>> &g) {
    cout << "Possible" << endl;
    for(ll i{1}; i<=3; i++) {
        for(ll j{1}; j<=w; j++) cout << g[i][j];
        cout << endl;
    }
}


void fast() {
    ll a,b; cin >> w >> a >> b;
    vector<vector<char>> grid(4,vector<char>(w+1,'.'));
    grid[2][1] = 'X';
    grid[1][a] = 'A';
    grid[3][b] = 'B';

    ll diff = abs(a-b);
    if(!diff) print(grid);
    else if(a==1&&b!=1 || a!=1&&b==1) cout << "Impossible";
    else {
        vector<ll>possible; bool two{false};
        if(min(a,b) > 2) two=true;
        for(ll i{4}; i<100; i+=2) possible.pb(i);

        if(binary_search(all(possible),diff) || diff==2&&two&&(a!=1||b!=1)) {
            ll cnt{};
            if(diff!=2) cnt = lower_bound(all(possible),diff)-possible.begin()+1;
            if(a < b) {
                for(ll i{1}; i<a; i++) grid[1][i]='*';
                for(ll i{2}; i<a; i++) grid[2][i]='*';
                for(ll i{a}; cnt; i++,cnt--) grid[2][i]='*';
            }
            else {
                for(ll i{1}; i<b; i++) grid[3][i]='*';
                for(ll i{2}; i<b; i++) grid[2][i]='*';
                for(ll i{b}; cnt; i++,cnt--) grid[2][i]='*';
            }
            print(grid);
        }
        else cout << "Impossible";
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
