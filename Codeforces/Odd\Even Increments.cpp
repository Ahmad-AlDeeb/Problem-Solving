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
        vector<ll>vec(n+1);
        for(ll i{1}; i<=n; i++) {
            ll num; cin >> num;
            vec[i] = num;
        }
        ll odds{1},evens{1};
        if(!(vec[1]&1)) odds=0;
        if(!(vec[2]&1)) evens=0;

        bool success{true};
        for(ll i{1}; i<=n; i++) {
            if(i&1 && vec[i]%2 != odds) success=false;
            if(!(i&1) && vec[i]%2 != evens) success=false;
        }
        if(success) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

}
