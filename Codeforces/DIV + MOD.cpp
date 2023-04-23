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
        ll n; cin >> n;
        vector<ll>vec(n); for(auto &i:vec) cin >> i;
        vector<ll>index(n+1);
        for(ll i{}; i<n; i++) index[vec[i]] = i;

        vector<ll>ans;
        for(ll i{n-1}; i>=0; i--) {
            ll value {i+1};
            ll val{vec[i]};
            for(ll k{1}; k<=n; k++) if(index[k] == i) {val=k; break;}

            if(val == value || !i) ans.pb(0);
            else {
                ll diff = i-index[value];
                for(ll j{1}; j<=i; j++)
                    index[j] = (index[j]+diff) % (i+1);
                ans.pb(abs(diff-(i+1)));
            }
        }
        reverse(all(ans));
        for(auto twist:ans) cout << twist << " ";
        cout << endl;
    }
}
