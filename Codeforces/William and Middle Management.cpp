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

ll get_period_sum(ll l, ll r, vector<ll> &v) {
    if(!l) return v[r];
    else return v[r]-v[l-1];
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n,k; cin >> n >> k;
    vector<ll>output(n);
    for(auto &i:output) {
        ll p,h; cin >> p >> h;
        i = p*h;
    }
    for(ll i{1}; i<n; i++)
        output[i] += output[i-1];

    vector<ll>bonus;
    for(ll l{},r{k-1}; r<n; l++,r++)
        bonus.pb(get_period_sum(l,r,output));
    sort(all(bonus));
    cout << bonus.back();
}
