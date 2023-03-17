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
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s,t; cin >> s >> t;
    bool automation{true};
    for(ll i{},j{}; i<t.size() && automation; i++) {
        bool found{false};
        for(; j<s.size() && !found; j++)
            if(t[i] == s[j]) found=true;
        if(!found) automation=false;
    }
    if(automation) {cout << "automaton"; return 0;}

    vector<ll>f1(26),f2(f1);
    for(auto c:s) f1[c-'a']++;
    for(auto c:t) f2[c-'a']++;

    bool arr{true};
    for(ll i{}; i<26; i++)
        if(f1[i] != f2[i]) arr=false;
    if(arr) {cout << "array"; return 0;}

    bool both{true};
    for(ll i{}; i<26; i++)
        if(f1[i] < f2[i]) both=false;
    if(both) {cout << "both"; return 0;}

    cout << "need tree";
}
