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
    ll n,l; cin >> n >> l;
    set<ll>s;
    while(n--) {ll x; cin >> x; s.insert(x);}

    ll prev{}; vector<ld>ans;

    ans.pb(*s.begin());
    for(auto i{s.begin()}; i!=s.end(); i++) {
        ans.pb((dd)(*i-prev)/2);
        prev = *i;
    }
    ans.pb(l-*(--s.end()));
    sort(all(ans));

    cout << fixed << setprecision(9) << ans.back();
}
