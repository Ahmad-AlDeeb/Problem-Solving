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
    ll n,m; cin >> n >> m;
    vector<vector<ll>>adj(n);
    while(m--) {
        ll a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll ans{};
    while(true) {
        bool success=false;
        vector<ll>failed;
        for(ll i{}; i<n; i++)
            if(adj[i].size() == 1) {
                success=true;
                failed.pb(i);
                adj[i].clear();
            }

        for(auto person:failed) {
            vector<ll> &v = adj[adj[person].front()];
            for(ll i{}; i<v.size(); i++) {
                if(v[i] == person) {
                    v.erase(v.begin()+i);
                    break;
                }
            }
        }

        if(success) ans++;
        else break;
    }
    cout << ans;
}
