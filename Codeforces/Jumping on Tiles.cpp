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
        string s; cin >> s;
        ll mini = min(alphabet.find(s.front()),alphabet.find(s.back()));
        ll maxi = max(alphabet.find(s.front()),alphabet.find(s.back()));
        ll cost {maxi-mini};
        vector<pair<ll,ll>>tiles;
        for(ll i{1}; i<s.size()-1; i++) {
            ll value = alphabet.find(s[i]);
            if(value>=mini && value<=maxi) tiles.emplace_back(value,i+1);
        }
        if(mini == alphabet.find(s.front()))
            sort(all(tiles));
        else sort(all(tiles),greater<>());

        cout << cost << " " << tiles.size()+2 << endl;
        cout << 1 << " ";
        for(auto tile:tiles) cout << tile.S << " ";
        cout << s.size() << endl;
    }
}
