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
const ll M = 1e5;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t,x1,y1,x2,y2; cin >> t >> x1 >> y1 >> x2 >> y2;

    ll n{},s{},e{},w{};
    if(x1 > x2) w = x1-x2;
    else if(x1 < x2) e = x2-x1;
    if(y1 > y2) s = y1-y2;
    else if(y1 < y2) n = y2-y1;

    ll N{},S{},E{},W{};
    string dir; cin >> dir;
    for(auto d:dir) {
        if(d=='N') N++;
        if(d=='S') S++;
        if(d=='E') E++;
        if(d=='W') W++;
    }
    if(N>=n && S>=s && E>=e && W>=w) {
        for(ll i{}; i<t; i++) {
            if(!n && !s && !e && !w) {cout << i; return 0;}
            if(dir[i]=='N' && n) n--;
            if(dir[i]=='S' && s) s--;
            if(dir[i]=='E' && e) e--;
            if(dir[i]=='W' && w) w--;
        }
        cout << t;
    }
    else cout << -1;



}
