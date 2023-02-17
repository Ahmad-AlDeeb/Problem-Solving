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
    ll t; cin >> t;
    while(t--) {
        ll n,k; cin >> n >> k;
        map<ll,ll>f;
        while(n--) {ll x; cin >> x; f[x]++;}
        vector<ll>vec;
        for(pair<ll,ll> p:f)
            if(p.S >= k)
                vec.pb(p.F);
        if(vec.empty()) {cout << -1 << endl; continue;}
        sort(all(vec));

        vector<pair<ll,ll>>ans;
        ll start{vec.front()},end{vec.front()};
        ans.emplace_back(start,end);

        for(ll i{1}; i<vec.size(); i++) {
            if(vec[i]==vec[i-1]+1) end=vec[i];
            else {
                ans.emplace_back(start,end);
                start = end = vec[i];
            }

            if(i == vec.size()-1) {
                end = vec[i];
                ans.emplace_back(start,end);
            }
        }

        pair<ll,ll>maxi{ans.front()};
        for(ll i{1}; i<ans.size(); i++)
            if(ans[i].S-ans[i].F > maxi.S-maxi.F)
                maxi = ans[i];
        ll ans1 = maxi.F;
        ll ans2 = maxi.S;

        cout << ans1 << " " << ans2 << endl;
    }
}
