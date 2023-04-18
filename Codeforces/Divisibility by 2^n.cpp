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
    ll tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        ll x{};
        for(ll i{}; i<n; i++) {
            ll num; cin >> num;
            while(num%2 == 0) {x++; num/=2;}
        }
        ll rem = n-x;
        if(rem <= 0) cout << 0 << endl;
        else {
            priority_queue<ll>pq;
            for(ll i{2}; i<=n; i++) {
                ll num {i},cnt{};
                while(num%2 == 0) {cnt++; num/=2;}
                if(cnt>0) pq.push(cnt);
            }

            ll op{};
            while(rem>0 and !pq.empty()) rem-=pq.top(),pq.pop(),op++;
            if(rem <= 0) cout << op; else cout << -1;
            cout << endl;
        }

    }
}
