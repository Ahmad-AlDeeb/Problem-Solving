#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/////////////////////////// MACROS ///////////////////////////
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define ordered_set tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>

/// CONST variables ///
const ll inf = 1e18;
const ll M = 1e9+7;
const ll SZ = 200005;
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-18;

///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    ll n,k; cin >> n >> k;
    vll v(n); for(auto &i:v) cin >> i;

    vll diff; ll ans{};
    for(ll i{}; i<n-1; i++)
        diff.pb( abs(v[i]-v[i+1]) ), ans+=diff.back();
    sort(all(diff),greater<>());
    
    for(auto num:diff) {
        if(--k) ans -= num;
        else break;
    }
    cout << ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
     cin >> tc;
    while(tc--) {
        fast();
         cout << endl;
    }

    ///////////////// Stress testing /////////////////
//    while(true) {
////        ll n = 2601;
//        ll n = rand()%10+1;
//        if(fast(n) == slow(n)) cout << n << " OK!\n";
//        else {
//            cout << "NOT MATCHED!\n";
//            cout << n << endl << slow(n) << " " << fast(n);
//            break;
//        }
//    }
}
