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
        ll n; string s; cin >> n >> s;
        bool w{false},b{w},r{w};
        bool success{true};

        for(ll i{}; i<s.size(); i++) {
            if(s[i]=='W' || i==s.size()-1) {
                if(s[i]=='B') b=true;
                if(s[i]=='R') r=true;

                if((!b && r) or (b && !r)) success=false;
                b=r=false;
            }
            if(s[i]=='B') b=true;
            if(s[i]=='R') r=true;

        }
        if(success) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
