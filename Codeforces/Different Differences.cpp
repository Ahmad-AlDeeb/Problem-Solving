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
    ll t;  cin >> t;
    while(t--) {
        ll k,n; cin >> k >> n;
        vector<ll>vec(k);
        for(ll i{1}; i<=k; i++) vec[i - 1]=i;
        vector<ll>diffs{1};
        for(ll i{}; i<k-1; i++)
            diffs.pb(diffs.back()+vec[i]);




        vector<ll>ans;
        ll i{};
        for(; i<k; i++) {
            ll val = diffs[i];
            if(n-val+1>k-i-1 && val<=n) ans.pb(val);
            else break;
        }
        while(i++<k) ans.pb(ans.back()+1);

        for(auto num:ans) cout << num << " ";
        cout << endl;
    }

}
