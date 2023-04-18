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
        ll n; char c; string s; cin >> n >> c >> s;
        if(c=='g') {cout << 0 << endl; continue;}

        ll ans{};
        for(ll i{}; i<n; i++)
            if(s[i] == c) {
                ll cnt{1};
                for(i++; i<n && s[i]!='g'; cnt++,i++);
                ans = max(ans,cnt);
            }

        ll last_g;
        for(ll i=n-1; i>=0; i--)
            if(s[i] == 'g') {last_g = i; break;}
        ll last_c{-1};
        ll i{last_g+1}; i%=n;
        for(; i<n; i++) if(s[i]==c) {last_c=i; break;}

        if(last_c == -1) cout << ans << endl;
        else {
            ll cnt{1};
            i=last_c+1; i%=n;
            for(; s[i]!='g'; cnt++,i++,i%=n);
            cout << max(ans,cnt) << endl;
        }

    }
}
