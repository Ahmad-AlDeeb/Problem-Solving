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

////////////////////////////// Priority Queue SOLUTION /////////////////////////////
int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        priority_queue<ll>boxes; ll sum{};
        while(m--) {
            ll box; cin >> box;
            sum += box;
            boxes.push(box);
        }
        if(sum < n) {cout << -1 << endl; continue;}

        ll divisions{};
        while(n) {
            ll biggest{boxes.top()};
            boxes.pop();

            if(biggest <= n) {
                n -= biggest;
                sum -= biggest;
            }
            else if(sum-biggest < n) {
                divisions++;
                boxes.push(biggest/2);
                boxes.push(biggest/2);
            }
            else sum -= biggest;
        }
        cout << divisions << endl;
    }
}
