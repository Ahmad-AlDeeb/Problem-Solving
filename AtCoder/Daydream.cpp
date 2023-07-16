#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    string s,t; cin >> s;
    ll sz = s.size();
    
    for(ll i{};i<sz; i++) {
        t += s[i];

        if(t=="dream") {
            if(i<=sz-3&&s[i+1]=='e'&&s[i+2]=='r') {
                bool cool{false};
                string t2;
                for(ll j{i+1}; j<sz; j++) {
                    t2 += s[j];
                    if(t2=="erase") {
                        cool=true;
                        i=j;
                        if(i!=sz-1 && s[i+1]=='r') i++;
                    }
                    if(t2.size()==5) break;
                }
                if(!cool) i+=2;
            }
            t.clear();
        }
        
        if(t=="erase") {
            if(i<sz-1&&s[i+1]=='r') i++;
            t.clear();
        }
    }
    if(t.empty()) cout << "YES";
    else cout << "NO";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
   // cin >> tc;
    while(tc--) {
        fast();
      // cout << endl;
    }
}
