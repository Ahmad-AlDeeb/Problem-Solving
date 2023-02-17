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
const ll M = 1e5;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,q; cin >> n >> q;
        vector<ll>can(n);
        ll sum{};
        for(auto &i:can) {
            cin >> i;
            sum += i;
        } sort(all(can));

        vector<ll>prefix{can};
        sort(all(prefix),greater<>());
        for(ll i{1}; i<prefix.size(); i++)
            prefix[i] += prefix[i-1];


        while(q--) {
            ll x; cin >> x;
            if(x > sum) cout << -1;
            else if(lower_bound(all(can),x) != can.end()) cout << 1;
            else {
                if(binary_search(all(prefix),x)) cout << lower_bound(all(prefix),x) - prefix.begin()+1;
                else cout << upper_bound(all(prefix),x) - prefix.begin()+1;
            }
            cout << endl;
        }
    }
}
