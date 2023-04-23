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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll tc; cin >> tc;
    while(tc--) {
        ll n,m; cin >> n >> m;
        vector<pair<ll,pair<ll,ll>>> points;

        for(ll i{1}; i<=m; i++) {
            ll x,w; cin >> x >> w;
            points.emplace_back(w,make_pair(x,i));
        }
        sort(all(points));

        ll total{};
        vector<pair<ll,ll>>points2;
        for(ll i{}; i<n*2; i++) {
            total += points[i].F;
            points2.emplace_back(points[i].S.F,points[i].S.S);
        }
        sort(all(points2));

        cout << total << endl;
        for(ll i{},j=points2.size()-1; i<j; i++,j--)
            cout << points2[i].S << " " << points2[j].S << endl;
        cout << endl;
    }
}
