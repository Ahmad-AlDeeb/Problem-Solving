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
        string s; ll p; cin >> s >> p;
        vector<ll>freq(26);
        for(auto c:s) freq[c-'a']++;

        ll total{};
        for(ll i{}; i<26; i++) total += freq[i]*(i+1);


        string to_delete;
        char ch_to_delete;
        for(ll c{25}; c >= 0; c--) {
            if(!freq[c]) continue;
            ll price {(c+1)*freq[c]};
            if(total-price < p) {
                ch_to_delete = static_cast<char>(c+'a');
                break;
            }
            else {
                to_delete += static_cast<char>(c+'a');
                total -= price;
            }
        }

        string ans;
        for(auto c:s) {
            if(to_delete.find(c) != string::npos) continue;
            else if(c == ch_to_delete && total>p)
                total -= (c-'a'+1);
            else ans += c;
        }
        cout << ans << endl;
    }
}
