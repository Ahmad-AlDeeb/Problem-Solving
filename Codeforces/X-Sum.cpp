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


ll n,m;
vector<vector<ll>> grid;
ll calc_sum(ll i, ll j) {
    ll sum{};

    // Down-Right
    for(ll a{i},b{j}; a<n && b<m; a++,b++)
        sum += grid[a][b];
    // Down-Left
    for(ll a{i},b{j}; a<n && b>=0; a++,b--)
        sum += grid[a][b];
    // Up-Right
    for(ll a{i},b{j}; a>=0 && b<m; a--,b++)
        sum += grid[a][b];
    // Up-Left
    for(ll a{i},b{j}; a>=0 && b>=0; a--,b--)
        sum += grid[a][b];

    return sum-(3*grid[i][j]);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        cin >> n >> m;
        grid = vector<vector<ll>> (n,vector<ll>(m)) ;
        for(auto &i:grid) for(auto &j:i) cin >> j;

        ll ans{};
        for(ll i{}; i<n; i++)
            for(ll j{}; j<m; j++)
                ans = max(ans,calc_sum(i,j));
        cout << ans << endl;
    }
}
