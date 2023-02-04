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
        ll n; string s; cin >> n >> s;
        vector<ll>f1(26),f2(26);
        ll dis1{1},dis2{};
        f1[s[0]-'a']++;
        for(ll i{1}; i<n; i++) {
            if(!f2[s[i]-'a']) dis2++;
            f2[s[i]-'a']++;
        }

        ll maxi{dis1 + dis2};
        for(ll i{1}; i<n-1; i++) {
            if(!f1[s[i]-'a']) dis1++;
            f1[s[i]-'a']++;
            f2[s[i]-'a']--;
            if(!f2[s[i]-'a']) dis2--;

            maxi = max(maxi,dis1+dis2);
        } cout << maxi << endl;
    }
}
