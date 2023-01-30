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

vector<ll> p_fact(ll x) {
    int i{2}; vector<ll> p;
    for(;i*i <= x; i++)
        while(x%i == 0) {
            x /= i; // we keep dividing as long as i divides x
            p.push_back(i); // and we push to factors vector
        }
    if(x != 1) p.push_back(x);
    return p;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> fact = p_fact(n);
        vector<set<ll>>terms(40);
        for(ll i{}; i<fact.size(); i++) {
            ll num = fact[i];
            for(ll j{}; j<terms.size(); j++) {
                ll size = terms[j].size();
                terms[j].insert(num);
                if(terms[j].size() != size) break;
            }
        }
        ll sum{};
        for(auto term:terms) {
            if(term.empty()) break;
            ll pro{1};
            for(auto num:term) pro *= num;
            sum += pro;
        }
        cout << sum << endl;
    }
}
