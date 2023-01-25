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

ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t;  cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll>vec(n); for(auto &i:vec) cin >> i;

        vector<ll>sum(vec);
        for(ll i{}; i<n-1; i++)
            sum[i+1] += sum[i];

        ll ans{};
        for(ll i{}; i<n-1; i++)
            ans = max(ans,gcd(sum[i],sum.back()-sum[i]));
        cout << ans << endl;
    }

}
