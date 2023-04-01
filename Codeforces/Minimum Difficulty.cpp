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

ll get_score(ll pts, ll time) {

    return max(3*pts/10, pts-pts/250*time);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>v(n); for(auto &i:v) cin >> i;
    ll ans{inf};
    for(ll i{1}; i<n-1; i++) {
        ll maxi{};

        for(ll j{}; j<n-1; j++) {
            if(j == i-1)
                maxi = max(v[j+2]-v[j], maxi);
            else if(j == i) continue;
            else maxi = max(v[j+1]-v[j], maxi);
        }
        
        ans = min(ans,maxi);
    }
    cout << ans;
}
