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

bool is_valid(ld num) {
    ll int_num = num;
    if(num == int_num) return true;
    return false;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        map<ll,ll>freq;
        while(n--) {
            ll x; cin >> x; freq[x%m]++;
        }

        ll ans{}; if(freq[0]) ans++;
        for(auto f:freq) {
            if(f.F <= m/2) {
                if(!f.F) continue;
                ll n1=f.F, n2=m-f.F;
                ans++;
                if(n1 != n2 and freq[n1]!=freq[n2])
                    ans += max(freq[n1],freq[n2]) - (min(freq[n1],freq[n2])+1);
                freq[n1] = freq[n2] = 0;
            }
        }
        for(auto f:freq)
            if(f.F > m/2 and f.S) ans += f.S;

        cout << ans << endl;
    }
}
