#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
#include<sstream>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
string letters(" abcdefghijklmnopqrstuvwxyz");

ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M)*(x%M)) % M;
        y /= 2;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    if(b!=0) return gcd(b,a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a*b / gcd(a,b);
}

int main() { // freopen("tabs.in","r",stdin);


    ll n,m; cin >> n >> m;
    vector<ll>stat(m);
    ll l; cin >> l;
    while(l--) {
        ll x; cin >> x; x--;
        stat[x]=1;
    }
    vector<vector<ll>>switches;
    while(n--) {
        ll size; cin >> size;
        vector<ll>my_switch(size);
        for(ll i{}; i<size; i++) {
            ll lamp; cin >> lamp; lamp--;
            my_switch[i] = lamp;
        }
        switches.pb(my_switch);
    }


    bool success{false}; ll cnt{};
    for(auto s:switches) {
        for(auto lamp:s)
            stat[lamp]++;
        bool all_even{true};
        for(auto num:stat)
            if(num&1) all_even=false;
        cnt++;

        if(all_even) {success=true; break;}
    }
    if(success) {cout << cnt; return 0;}

    for(auto s:switches) {
        for(auto lamp:s)
            stat[lamp]++;
        bool all_even{true};
        for(auto num:stat)
            if(num&1) all_even=false;
        cnt++;

        if(all_even) {success=true; break;}
    }
    if(success) cout << cnt;
    else cout << -1;
}
