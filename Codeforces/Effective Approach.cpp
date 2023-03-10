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
    ll n; cin >> n;
    vector<ll>vec(n+1);
    for(ll i{1}; i<=n; i++) {ll x; cin >> x; vec[i]=x;}

    vector<ll>delta(n+1);
    for(ll i{1}; i<=n; i++)
        delta[vec[i]] = i-vec[i];

    ll ans1{},ans2{};
    ll m; cin >> m;
    while(m--) {
        ll q; cin >> q;
        ans1 += q + delta[q];
        ans2 += (n-q+1) - delta[q];
    }
    cout << ans1 << " " << ans2;

}
