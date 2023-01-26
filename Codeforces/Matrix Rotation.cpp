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


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t;  cin >> t;
    while(t--) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        ll small = min({a,b,c,d});
        if(a==small) {
            if(d>b && d>c) cout << "YES";
            else cout << "NO";
        }
        else if(b==small) {
            if(c>d && c>a) cout << "YES";
            else cout << "NO";
        }
        else if(c==small) {
            if(b>d && b>a) cout << "YES";
            else cout << "NO";
        }
        else if(d==small) {
            if(a>c && a>b) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
}
