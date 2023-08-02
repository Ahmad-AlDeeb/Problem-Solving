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
const ll N = 1e5+5;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS = 1e-19;
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
    string s; cin >> s;
    ll sz = s.size();
    set<char>st;

    ll last_a{};
    for(ll i{}; i<sz; i++) {
        st.insert(s[i]);
        if(s[i]=='a') last_a=i;
    }
    if(st.size()==1 && *st.begin()=='a') {cout << s; return;}



    string l,r;
    for(ll i{}; i<sz; i++) {
        if(i<=last_a) {if(s[i]!='a') l+=s[i];}
        else {
            if(sz-i > l.size())
                l+=s[i];
            else r+=s[i];
        }
    }


    if(l.size()==r.size()) {
        bool cool{true};
        for(ll i{}; i<l.size(); i++)
            if(l[i]!=r[i]) cool=false;

        if(cool) {
            string ans; bool end{false};
            for(ll i{},j{}; i<sz; i++) {
                if(s[i]==l[j]) {
                    if(end) break;
                    j++;
                    if(j==l.size())
                        j=0,end=true;
                }
                ans += s[i];
            }
            cout << ans;
            return;
        }
    }
    cout << ":(";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        fast();
//        cout << endl;
    }
}
