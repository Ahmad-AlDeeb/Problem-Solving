#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() { IOS
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll res{n}; vector<pair<ll,ll>>ans;
        for(ll i{n-1}; i>=1; i--) {
            ans.emplace_back(res, i);
            ((res+i)%2 == 1)? res=(res+i)/2+1 : res=(res+i)/2;
        }
        cout << res << endl;
        for(auto p:ans) cout << p.x << " " << p.y << endl;
    }
}
