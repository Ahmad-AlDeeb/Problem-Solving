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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll a,b,n,m; cin >> a >> b >> n >> m;
        ll cost1 = n/(m+1) * m * a;
        if(n%(m+1) != 0) {
            if(a <= b) cost1 += n%(m+1) * a;
            else cost1 += n%(m+1) * b;
        }

        ll cost2 = n * b;
        cout << min(cost1,cost2) << endl;
    }
}
