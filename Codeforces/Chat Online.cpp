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
    ll p,q,l,r; cin >> p >> q >> l >> r;
    vector<pair<ll,ll>>Z;
    while(p--) {
        ll a,b; cin >> a >> b;
        Z.emplace_back(a,b);
    }
    vector<pair<ll,ll>>X;
    while(q--) {
        ll a,b; cin >> a >> b;
        X.emplace_back(a,b);
    }

    ll ans{};
    for(ll i{l}; i<=r; i++) {
        bool success{false};
        for(auto range:X) {
            ll start = range.F+i;
            ll end = range.S+i;
            for(auto range2:Z)
                if(start<=range2.S and end>=range2.F)
                    success=true;
        }
        if(success) ans++;
    }
    cout << ans;
}
