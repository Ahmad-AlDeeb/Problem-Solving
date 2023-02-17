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
        ll n,m; cin >> n >> m;
        vector<string>vec(n); for(auto &i:vec) cin >> i;

        ll ans{inf};
        for(ll a{}; a<n; a++)
            for(ll b{a+1}; b<n; b++) {
                ll sum{};
                for(ll i{}; i<m; i++) {
                    ll diff = abs(vec[a][i]-vec[b][i]);
//                    ll num1 = 'z'-vec[a][i] + vec[b][i]-'a' +1;
//                    ll num2 = 'z'-vec[b][i] + vec[a][i]-'a' +1;

                    if(vec[a][i] > vec[b][i]) sum += diff;
                    else                  sum += diff;
                }
                ans = min(ans,sum);
            }
        cout << ans << endl;
    }
}
