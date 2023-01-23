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


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll u,v; cin >> u >> v;
    ll diff = v-u;

    if(u%2!=v%2 || u>v) cout << -1;
    else if(u == v) {
        if(!u) cout << 0;
        else cout << 1 << endl << u;
    }

    else if(u & (diff/2)) // when AND operation return 0 means that XOR = normal addition :D !
        cout << 3 << endl << u << " " << diff/2 << " " << diff/2;
    else cout << 2 << endl << (u^(diff/2)) << " " << diff/2;
}
