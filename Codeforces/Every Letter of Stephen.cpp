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
    ll t; cin>>t;
    while(t--) {
        ll n; cin >> n;
        vector<string>lines(n); for(auto &line:lines) cin >> line;
        vector<ll>freq(26); for(auto &f:freq) cin >> f;

        for(auto line:lines) {
            vector<ll>non_lower(100);
            for(auto c:line)
                if(!islower(c)) non_lower[c-'!']++;

            vector<ll>index(100,-1);
            for(ll i{}; i<non_lower.size(); i++)
                for(ll j{}; j<freq.size(); j++)
                    if(non_lower[i]==0) break;
                    else if(non_lower[i]==freq[j])
                        index[i] = j;

            for(auto c:line) {
                if(islower(c)) cout << c;
                else cout << static_cast<char>(index[c-'!']+'a');
            }
            cout << endl;
        }
    }
}
