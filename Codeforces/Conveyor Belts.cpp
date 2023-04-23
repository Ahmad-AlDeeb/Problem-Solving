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
ll n;
ll get_lvl(ll loc) {
    ll steps = loc - (n / 2 + 1);
    loc--;
    return loc - (steps * 2);
}
ll get_loc(ll x, ll y) {
    if(max(x, y) <= n/2) return min(x,y);
    else {
        if(x > n / 2) x = get_lvl(x);
        if(y > n / 2) y = get_lvl(y);
        return min(x, y);
    }
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll x1,y1,x2,y2; cin >> n >> x1 >> y1 >> x2 >> y2;
        cout << abs(get_loc(x1,y1) - get_loc(x2,y2)) << endl;
    }
}