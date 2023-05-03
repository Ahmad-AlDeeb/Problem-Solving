#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<sstream>
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
const ll SZ = 200005;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};
string letters{" abcdefghijklmnopqrstuvwxyz"};

ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a*b / gcd(a,b);
}
ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
vector<ll> p_fact(ll x) {
    ll i{2}; vector<ll> p;
    for(; i*i <= x; i++) {
        if(x%i == 0) p.pb(i);
        while(x%i == 0) x /= i;
    }
    if(x != 1) p.push_back(x);
    return p;
}
bool is_int(dd double_num) {
    int int_num = double_num;
    if(int_num == double_num)
        return true;
    return false;
}
bool is_prime(ll x) {
    for(ll i{2}; i*i<=x; i++)
        if(x%i == 0) return false;
    return true;
}
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}
vector<ll> sieve(ll n) {
    vector<bool>primes(n+1,true);
    for(ll i{2}; i*i<=n; i++)
        if(primes[i])
            for(ll j{i*i}; j<=n; j+=i)
                primes[j]=false;

    vector<ll>ans;
    for(ll i{2}; i<=n; i++)
        if(primes[i]) ans.pb(i);
    return ans;
}
/////////////////////////////////////////////////////////////////////////////////////

void fast() {
    ll n; cin >> n;
    vector<pair<ll,string>>code1;
    for(ll j{}; j<n; j++) {
        string s; cin >> s;

        if(s == "define") {
            string var; cin >> var;
            code1.emplace_back(1,var);
        }
        else if(s == "read") {
            string var; cin >> var;
            code1.emplace_back(2,var);
        }
        else if(s == "print") {
            string var; cin >> var;
            code1.emplace_back(3,var);
        }
        else {
            string s1,s2,s3; bool equal{false},plus{false};
            for(ll i{}; i<s.size(); i++) {
                if(s[i] == '=') {equal=true; continue;}
                else if(s[i] == '+') {plus=true; continue;}

                if(!equal) s1 += s[i];
                else if(!plus) s2 += s[i];
                else s3 += s[i];
            }
            string var;
            var.append(s1);
            var.append(s2);
            var.append(s3);
            code1.emplace_back(4,var);
        }
    }

    map<string,string>MAP;
    vector<pair<ll,string>>code2;
    ll m; cin >> m;
    if(m!= n) {cout << "NO"; return;}
    for(ll j{}; j<m; j++) {
        string s; cin >> s;

        if(s == "define") {
            string var; cin >> var;
            MAP[var] = code1[j].S;
            code2.emplace_back(1,MAP[var]);
        }
        else if(s == "read") {
            string var; cin >> var;
            code2.emplace_back(2,MAP[var]);
        }
        else if(s == "print") {
            string var; cin >> var;
            code2.emplace_back(3,MAP[var]);
        }
        else {
            string s1,s2,s3; bool equal{false},plus{false};
            for(ll i{}; i<s.size(); i++) {
                if(s[i] == '=') {equal=true; continue;}
                else if(s[i] == '+') {plus=true; continue;}

                if(!equal) s1 += s[i];
                else if(!plus) s2 += s[i];
                else s3 += s[i];
            }
            string var;
            var.append(MAP[s1]);
            var.append(MAP[s2]);
            var.append(MAP[s3]);
            code2.emplace_back(4,var);
        }
    }

    if(code1 == code2) cout << "YES"; else cout << "NO";
}
/////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
