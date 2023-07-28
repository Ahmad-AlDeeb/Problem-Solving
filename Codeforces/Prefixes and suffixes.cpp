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
const ll N = 100;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS {1e-19};
const ld PI {3.14159265358979323846};
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
ll n;
string get_str(string s1, string s2, string s3) {
    string str; bool cool{true};
    for(ll i{}; i<n-2; i++) {
        if(s1[i+1] != s2[i]) {cool=false; str.clear(); break;}
        str+=s2[i];
    }
    if(!cool) return str;
    str = s1.front() + str + s2.back();

    string pre_suf; pre_suf+=s1.front(), pre_suf+=s2.back(); sort(all(pre_suf));

    if(pre_suf != s3) str.clear();
    return str;
}
string get_print(string str, vector<string> &v) {
    vector<pair<string,char>> ans;
    for(ll len{1}; len<=n-1; len++)
        ans.emplace_back(str.substr(0,len),'P');
    for(ll i{n-1},len{1}; i>0; i--,len++)
        ans.emplace_back(str.substr(i,len),'S');

    string print;
    for(auto &s:v)
        for(auto &p:ans)
            if(s == p.F) {print+=p.S; p.F=""; break;}
    return print;
}
void fast() {
    cin >> n;
    string s1,s2; char a{'.'},z{'.'};
    vector<string> v(n*2-2);
    for(auto &i:v) {
        cin >> i;
        if(i.size() == n-1) {
            if(s1.empty()) s1=i;
            else s2=i;
        }
        if(i.size() == 1) {
            if(a=='.') a=i.front();
            else z=i.front();
        }
    }

    string s3; s3+=a,s3+=z; sort(all(s3));

    string str1 = get_str(s1,s2,s3);
    string str2 = get_str(s2,s1,s3);

    string ans1,ans2;
    if(!str1.empty()) ans1 = get_print(str1,v);
    if(!str2.empty()) ans2 = get_print(str2,v);

    if(ans1.size()==2*n-2) cout << ans1;
    else cout << ans2;
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
