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
string alphabet{" abcdefghijklmnopqrstuvwxyz"};


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        vector<ll>x(n); for(auto &i:x) cin >> i;
        vector<ll>y(n); for(auto &i:y) cin >> i;
        vector<ll>vec(n);
        for(ll i{}; i<n; i++) vec[i] = y[i]-x[i];

        vector<ll>pos,neg; ll zeros{};
        for(auto num:vec) {
            if(num<0) neg.pb(num);
            else if(num>0) pos.pb(num);
            else zeros++;
        }
        sort(all(neg)); sort(all(pos),greater<>());
        ll ans{};
        ll i{},j{};
        while(i<neg.size() and j<pos.size()) {
            if(neg[i]+pos[j] >= 0) ans++,j++;
            i++;
        }
        if(j != pos.size()) ans += (pos.size()-j+zeros)/2;
        else ans += zeros/2;
        cout << ans << endl;
    }
}
