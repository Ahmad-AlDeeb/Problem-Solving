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
string letters{"abcdefghijklmnopqrstuvwxyz"};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--) {
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        vector<ll>prefix(s.size()+1);
        for(ll i{}; i<n; i++)
            if(s[i]=='B')
                prefix[i+1]=1;
        for(ll i{1}; i<=n; i++) prefix[i] += prefix[i-1];

        ll ans{k};
        for(ll i{1},j{k}; j<=n; i++,j++) {
            ll whites = k - (prefix[j]-prefix[i-1]);
            ans = min(ans,whites);
        }
        cout << ans << endl;
    }
}
