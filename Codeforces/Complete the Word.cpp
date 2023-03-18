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
    string s; cin >> s;
    if(s.size()<26) {cout << -1; return 0;}
    for(ll i{}; i<=s.size()-26; i++) {

        vector<ll>f(26); ll marks{};
        for(ll j{i},cnt{}; cnt<26; j++,cnt++) {
            if(isupper(s[j])) f[s[j]-'A']++;
            else marks++;
        }
        ll zeros{};
        for(auto freq:f) if(!freq) zeros++;

        if(marks == zeros) {
            for(ll j{i},cnt{},k{}; cnt<26; j++,cnt++)
                while(!isupper(s[j])) {
                    if(!f[k]) s[j]=k+'A';
                    k++;
                }
            for(auto &c:s) if(!isupper(c)) c='A';
            cout << s;
            return 0;
        }
    }
    cout << -1;
}
