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
        ll n,t; cin >> n >> t;
        vector<ll>vec(n);
        for(ll i{}; i<n; i++) {
            cin >> vec[i];
            vec[i]+=i;
        }
        vector<pair<ll,pair<ll,ll>>> pairs;
        vector<ll>b(n);
        for(ll i{}; i<n; i++) {
            cin >> b[i];
            pairs.emplace_back(b[i], make_pair(i,vec[i]));
        }
        sort(all(pairs),greater<>());
        ll ans{-1};
        for(auto &p:pairs)
            if(p.S.S <= t)
                {ans=p.S.F; break;}

        if(ans == -1) cout << -1;
        else cout << ans+1;
        cout << endl;
    }
}
