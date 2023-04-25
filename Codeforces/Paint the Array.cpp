#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
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
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};
string letters{" abcdefghijklmnopqrstuvwxyz"};
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        vector<ll>a,b;
        for(ll i{}; i<n; i++) {
            ll x; cin >> x;
            if(i&1) a.pb(x);
            else b.pb(x);
        }
        ll gcd1{a.front()};
        for(ll i{1}; i<a.size(); i++)
            gcd1 = gcd(gcd1,a[i]);
        bool success{true};
        for(auto num:b)
            if(num%gcd1 == 0) success=false;
        if(success) {cout << gcd1 << endl; continue;}

        ll gcd2{b.front()};
        for(ll i{1}; i<b.size(); i++)
            gcd2 = gcd(gcd2,b[i]);
        success=true;
        for(auto num:a)
            if(num%gcd2 == 0) success=false;
        if(success) cout << gcd2;
        else cout << 0;
        cout << endl;
    }

}
