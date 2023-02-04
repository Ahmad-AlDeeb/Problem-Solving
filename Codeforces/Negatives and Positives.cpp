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

ll calc_fun(string &s) {
    map<ll,ll>f;
    for(auto c:s) f[c]=1;
    return f.size();
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll sum{},odds{},mini{inf}; bool zero{false};
        vector<ll>vec(n);
        for(auto &i:vec) {
            cin >> i;
            sum+=abs(i);
            if(!i) zero=true;
            if(i<0) odds++;
            mini = min(mini,abs(i));
        }

        if(!zero and odds%2==1) cout << sum-(2*mini);
        else cout << sum;
        cout << endl;
    }
}
