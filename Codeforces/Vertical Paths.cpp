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
string letters{"abcdefghijklmnopqrstuvwxyz"};

ll max_lvl{-1};
vector<ll>path;
vector<vector<ll>>ans;
vector<vector<ll>>adj;
vector<bool>vis;
void dfs(ll node, ll lvl) {
    vis[node]=true;


    if(lvl <= max_lvl) {
        ans.pb(path);
        path.clear();
    }
    max_lvl = lvl;
    path.pb(node);


    for(auto child:adj[node])
        if(!vis[child]) dfs(child,lvl+1);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--) {
        max_lvl = -1;
        path.clear();
        ans.clear();

        ll n; cin >> n;
        vector<ll>vec(n);
        adj = vector<vector<ll>>(n+1);
        vis = vector<bool>(n+1,false);
        ll parent;
        for(ll i{1}; i<=n; i++) {
            ll value; cin >> value;
            if(value == i) parent = value;
            adj[value].pb(i);
        }

        dfs(parent,0);
        if(!path.empty()) ans.pb(path);

        cout << ans.size() << endl;
        for(auto v:ans) {
            cout << v.size() << endl;
            for(auto num:v) cout << num << " ";
            cout << endl;
        }
    }
}
