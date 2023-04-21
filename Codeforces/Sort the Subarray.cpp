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
        vector<ll>a(n),b(n);
        for(auto &i:a) cin >> i;
        for(auto &i:b) cin >> i;

        ll start;
        for(ll i{}; i<n; i++)
            if(a[i]!=b[i]) {start=i; break;}
        ll end;
        for(ll i{n-1}; i>=0; i--)
            if(a[i]!=b[i]) {end=i; break;}

        ll mini = *min_element(b.begin()+start,b.begin()+end+1);
        ll maxi = *max_element(b.begin()+start,b.begin()+end+1);

        for(ll i{start-1}; i>=0; i--) {
            if(b[i]<=mini) start--;
            else break;
            mini = b[i];
        }
        for(ll i{end+1}; i<n; i++) {
            if(b[i]>=maxi) end++;
            else break;
            maxi = b[i];
        }

        cout << start+1 << " " << end+1 << endl;
    }
}
