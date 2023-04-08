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
        ll n; string line; cin >> n >> line;

        ll sum{};
        for(ll i{}; i<n; i++) {
            if(line[i] == 'L') sum += i;
            else sum += n-i-1;
        }
        ll k{n};
        for(ll i{},j{n-1}; i<j; i++,j--) {
            if(line[i] == 'L') {
                sum -= i;
                sum += n-i-1;
                k--;
                cout << sum << " ";
            }
            if(line[j] == 'R') {
                sum -= n-j-1;
                sum += j;
                k--;
                cout << sum << " ";
            }
        }
        while(k--) cout << sum << " ";
        cout << endl;
    }
        
}
