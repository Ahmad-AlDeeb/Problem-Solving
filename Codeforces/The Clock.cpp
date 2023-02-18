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
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

bool is_palindrome(ll h, ll m) {
    string h_str=to_string(h), m_str=to_string(m);
    if(h_str.size() == 1) h_str = '0'+h_str;
    if(m_str.size() == 1) m_str = '0'+m_str;
    string s = h_str + m_str;

    bool success{true};
    for(ll i{},j=s.size()-1; i<s.size()/2; i++,j--)
        if(s[i] != s[j]) success=false;

    if(success) return true;
    else return false;
}
pair<ll,ll> increment(ll h, ll m, ll min) {
    ll hours = min/60;
    ll minutes = min%60;
    if(m+minutes >= 60) hours++;

    return make_pair((h+hours)%24, (m+minutes)%60);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        string s; ll min; cin >> s >> min;
        ll hours{},minutes{};
        hours += 10*(s[0]-'0') + s[1]-'0';
        minutes += 10*(s[3]-'0') + s[4]-'0';


        ll h{hours},m{minutes};
        ll ans{};
        do {
            if(is_palindrome(h,m)) ans++;
            pair<ll,ll> p = increment(h,m,min);
            h = p.F; m = p.S;
        } while(h!=hours || m!=minutes);
        cout << ans << endl;
    }
}
