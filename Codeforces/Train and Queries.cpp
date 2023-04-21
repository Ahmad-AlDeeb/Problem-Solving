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
        ll n,k; cin>>n>>k;
        map<ll,pair<ll,ll>>stations;
        map<ll,bool>values;
        vector<ll>vec(n);
        for(ll i{}; i<n; i++) {
            ll x; cin >> x; vec[i] = x;
            values[x]=true;
            stations[x].F = stations[x].S = i;
        }
        for(ll i{}; i<n; i++) {
            stations[vec[i]].F = min(i,stations[vec[i]].F);
            stations[vec[i]].S = max(i,stations[vec[i]].S);
        }

        while(k--) {
            ll a,b; cin >> a >> b;
            if(values[a] && values[b] and stations[a].F <= stations[b].S) cout << "YES";
            else cout<< "NO";
            cout << endl;
        }
    }
}
