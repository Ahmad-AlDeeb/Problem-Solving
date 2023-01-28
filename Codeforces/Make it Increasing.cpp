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

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;

    ll ans{inf};
    for(ll pos{}; pos<n; pos++) {
        ll prev{},sum{};
        for(ll i{pos-1}; i>=0; i--) {
            prev += vec[i] - (prev%vec[i]);
            sum += prev/vec[i];
        }
        prev = 0;
        for(ll i{pos+1}; i<n; i++) {
            prev += vec[i] - (prev%vec[i]);
            sum += prev/vec[i];
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}
