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
#include<unordered_set>
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
    ll n,q; cin >> n >> q;
    vector<string>vec(n); for(auto &i:vec) cin >> i;
    while(q--) {
        ll x; cin >> x;
        if(x==1) {
            string s; cin >> s;
            auto it = find(vec.begin(),vec.end(),s);
            if(it != vec.end()) vec.erase(it);
            else cout << "Not found" << endl;
        }
        else if(vec.empty()) cout << 0 << endl;
        else {
            if(x==2) for(ll i{}; i<vec.size(); i++) cout << vec[i] << " ";
            else     for(ll i=vec.size()-1; i>=0; i--) cout << vec[i] << " ";
            cout << endl;
        }

    }
}
