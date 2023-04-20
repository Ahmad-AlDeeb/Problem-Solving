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
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        vector<ll>vec(n); for(auto &i:vec) cin >> i;
        for(ll i{1}; i<n; i++) vec[i] += vec[i-1];

        ll ans{n};
        for(ll i{}; i<n; i++) {
            ll target{vec[i]},sum{vec[i]};
            ll maxi {i+1};
            ll size {};

            bool success{true};
            for(ll j{i+1}; j<n; j++) {
                size++;
                if(sum+target == vec[j]) {
                    sum += target;
                    maxi = max(maxi,size);
                    size = 0;
                }
                else if(sum+target < vec[j]) success=false;
            }
            if(success && sum==vec.back()) ans = min(ans,maxi);
        }
        cout << ans << endl;
    }
}
