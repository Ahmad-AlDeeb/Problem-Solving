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
        vector<ll>vec(n); for(auto &i:vec) cin >> i;

        ll mini{1},maxi{n}; bool success{false};
        for(ll i{},j{n-1}; i<j;) {
            if(vec[i]==mini) {i++; mini++; continue;}
            else if(vec[i]==maxi) {i++; maxi--; continue;}

            if(vec[j]==mini) {j--; mini++; continue;}
            else if(vec[j]==maxi) {j--; maxi--; continue;}

            success=true;
            cout << i+1 << " " << j+1 << endl; break;
        }
        if(!success) cout << -1 << endl;
    }
}
