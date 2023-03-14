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
    ll n,m,k; cin >> n >> m >> k;

    vector<bool>holes(n,false);
    while(m--) {
        ll hole; cin >> hole; hole--;
        holes[hole] = true;
    }
    if(holes.front()) {cout << 1; return 0;}

    vector<bool>cups(n,false);
    cups.front() = true;
    while(k--) {
        ll a,b; cin >> a >> b; a--; b--;
        if(cups[a]) {
            cups[a] = false;
            cups[b] = true;
            if(holes[b]) {cout << b+1; return 0;}
        }
        else if(cups[b]) {
            cups[a] = true;
            cups[b] = false;
            if(holes[a]) {cout << a+1; return 0;}
        }
    }
    for(ll i{}; i<n; i++)
        if(cups[i]) {cout << i+1; break;}

}
