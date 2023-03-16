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
    ll r1{};
    while(n--) {ll x; cin >> x; r1=max(r1,x);}

    ll m; cin >> m;
    ll p1{};
    while(m--) {ll x; cin >> x; p1=max(p1,x);}

    ll k; cin >> k;
    ll p2{inf};
    while(k--) {ll x; cin >> x; p2=min(p2,x);}

    ll a,b; cin >> a >> b;
    cout << fixed << setprecision(12) << (r1 * sqrt(b*p1/ (ld)(a*p2+b*p1) ));
}
