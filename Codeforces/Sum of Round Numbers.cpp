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
        string s; cin >> s;
        vector<ll>ans;
        for(ll i{}; i<s.size(); i++) {
            ll num {s[i]-'0'};
            if(s[i]!='0') ans.pb(num * pow(10,s.size()-1-i));
        }
        cout << ans.size() << endl;
        for(auto &i:ans) cout << i << " ";
        cout << endl;
    }

}
