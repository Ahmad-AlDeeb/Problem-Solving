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
        if(n==1) {cout << 1 << endl; continue;}
        if(n&1) {cout << -1 << endl; continue;}

        deque<ll>num;
        for(ll i{}; i<n; i++) num.pb(i);

        vector<ll>ans;
        bool at_front{true};
        while(!num.empty()) {
            ll diff = num.back()-num.front();

            if(at_front) ans.pb(diff), num.pop_front();
            else ans.pb(n-abs(diff)), num.pop_back();

            at_front = !at_front;
        }
        cout << ans.back() << " "; ans.pop_back();
        for(auto item:ans) cout << item << " ";
        cout << endl;
    }
}
