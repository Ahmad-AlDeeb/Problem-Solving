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

ll calc_fun(string &s) {
    map<ll,ll>f;
    for(auto c:s) f[c]=1;
    return f.size();
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,c; cin >> n >> c;
        vector<ll>cost;
        for(ll i{}; i<n; i++) {
            ll num; cin >> num;
            cost.pb(num+i+1);
        }
        sort(all(cost));
        ll ans{};
        for(auto co:cost)
            if(co <= c) {c-=co; ans++;}
        cout << ans << endl;
    }
}
