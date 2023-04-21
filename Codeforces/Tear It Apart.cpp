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
        string s; cin >> s;
        map<char,ll>f;
        for(auto c:s) f[c]++;
        if(f.size()==1) {cout << 0 << endl; continue;}

        vector<ll>ans; ans.pb((ll)log2(s.size()));

        for(ll i{}; i<26; i++) {
            ll maxi{},cnt{};
            for(ll j{}; j<s.size(); j++) {
                if(s[j]!=letters[i]) cnt++;
                else {
                    maxi = max(maxi,cnt);
                    cnt=0;
                }
            }
            maxi = max(maxi,cnt);
            if(maxi==1) ans.pb(1);
            else ans.pb((ll)log2(maxi)+1);
        }
        cout << *min_element(all(ans)) << endl;
    }
}
