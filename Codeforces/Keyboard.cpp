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

ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,m,x; cin >> n >> m >> x;
    vector<vector<char>>keys(n,vector<char>(m));
    vector<vector<pair<ll,ll>>>freq(26);
    vector<pair<ll,ll>>S_loc;

    for(ll i{}; i<n; i++)
        for(ll j{}; j<m; j++) {
            cin >> keys[i][j];
            if(keys[i][j] != 'S')
                freq[keys[i][j]-'a'].emplace_back(i,j);
            else S_loc.emplace_back(i,j);
        }

    vector<ld>char_dist(26,inf);
    for(ll i{}; i<26; i++) {

        for(auto locs:freq[i])
            for(auto s_loc:S_loc) {
                ll key_x {locs.F};
                ll key_y {locs.S};
                char_dist[i] = min(char_dist[i], distance(key_x, key_y, s_loc.F, s_loc.S));
            }
    }
    
    ll q; cin >> q;
    ll ans{};
    while(q--) {
        char input; cin >> input;
        bool found{false};
        for(auto &i:keys) for(auto &j:i) if(j == tolower(input)) found=true;
        if(!found) {cout << -1; return 0;}

        if(isupper(input)) {
            if(S_loc.empty()) {cout << -1; return 0;}
            if(char_dist[input-'A'] > x) ans++;
        }
    }
    cout << ans;
}
