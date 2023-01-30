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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        map<ll,ll>freq;
        while(n--) {ll num; cin >> num; freq[num]++;}
        
        map<ll,ll>freq_of_freq;
        for(auto p:freq) freq_of_freq[p.S]++;

        vector<ll>unique;
        for(auto pa:freq_of_freq) unique.pb(pa.F);

        ll mini{inf};
        for(auto uni:unique) {
            ll ans{};
            for(auto pa:freq_of_freq) {
                if(pa.F < uni) ans += pa.S*pa.F;
                if(pa.F > uni) ans += pa.S*(pa.F-uni);
            }
            mini = min(mini,ans);
        }
        cout << mini << endl;
    }
}
