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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    map<ll,vector<ll>>m;
    for(ll i{1}; i<=n; i++) {
        ll x; cin >> x;
        vector<ll> &stat = m[x];
        if(stat.empty())
            stat = vector<ll>{i,0,1};
        else {
            if(!stat[1]) {
                stat[1] = i-stat[0];
                stat[0] = i;
            }
            else {
                ll diff = i-stat[0];
                if(diff != stat[1]) stat[2] = 0;
                stat[0] = i;
            }
        }
    }

    set<pair<ll,ll>>s;
    for(auto &p:m) {
        vector<ll> &stat = p.S;
        if(stat[2])
            s.insert(make_pair(p.F,stat[1]));
    }
    cout << s.size() << endl;
    for(auto p:s)
        cout << p.F << " " << p.S << endl;

}
