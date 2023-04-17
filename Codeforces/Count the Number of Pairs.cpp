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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,k; cin >> n >> k; string s; cin >> s;
        vector<ll>big(26),small(26);
        for(auto c:s) {
            if(isupper(c)) big[c-'A']++;
            else small[c-'a']++;
        }

        ll ans{};
        for(ll i{}; i<26; i++) {
            ans += min(big[i],small[i]);

            if(k>0) {
                ll add = abs(big[i]-small[i])/2;
                ans += min(k,add);
                k -= add;
            }
        }
        cout << ans << endl;
    }
}
