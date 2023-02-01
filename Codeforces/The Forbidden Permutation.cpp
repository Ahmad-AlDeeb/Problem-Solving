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

int main() { IOS
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,m,d; cin >> n >> m >> d;
        vector<ll>perm(n),vec(m);
        for(auto &i:perm) cin >> i;
        for(auto &i:vec) cin >> i;

        map<ll,ll>f;
        for(ll i{}; i<n; i++)
            f[perm[i]] = i;

        vector<ll>ans;
        for(ll i{}; i<m-1; i++) {
            ll pos1 = f[vec[i]]; ll pos2 = f[vec[i+1]];

            if(pos1-pos2 > 0) ans.pb(0);
            else ans.pb(pos2-pos1);

            if(pos1+d < pos2) ans.pb(0);
            else {
                ll steps{pos1+d-pos2+1};
                if (steps <= pos1+(n-1-pos2))
                    ans.pb(steps);
            }
        }
        sort(all(ans));
        cout << ans.front() << endl;
    }
}
