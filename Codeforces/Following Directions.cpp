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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        pair<ll,ll> loc(0,0);

        string s; cin >> s;
        bool success{false};
        for(auto c:s) {
            if(c=='U') {
                loc.S++;
            }
            else if(c=='D') {
                loc.S--;
            }
            else if(c=='R') {
                loc.F++;
            }
            else {
                loc.F--;
            }

            if(loc.F==1 && loc.S==1)  success=true;
        }
        if(success) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
