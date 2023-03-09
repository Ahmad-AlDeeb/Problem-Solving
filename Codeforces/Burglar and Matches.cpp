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

bool is_valid(ld num) {
    ll int_num = num;
    if(num == int_num) return true;
    return false;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>>p;
    while(m--) {
        ll a,b; cin >> a >> b;
        p.emplace_back(b,a);
    } sort(all(p),greater<>());

    ll ans{};
    for(auto box:p) {
        if(n >= box.S) {ans += (box.F*box.S); n-=box.S;}
        else {ans += box.F*n; break;}
    }
    cout << ans;
}
