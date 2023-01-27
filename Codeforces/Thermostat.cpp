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
    string yes{"Yes"};
    ll t;  cin >> t;
    while(t--) {
        ll l,r,x,a,b; cin >> l >> r >> x >> a >> b;
        if(a==b && b>=l && b<=r) {cout << 0 << endl; continue;}

        ll l_size = abs(a-l), r_size = abs(r-a);
        bool l_valid{false},r_valid{false};
        if(l_size>=x) l_valid = true;
        if(r_size>=x) r_valid = true;

        if((b>=l && b<=r) and (l_valid || r_valid)) {
            if(a < b) {
                if(abs(b-a) >= x) cout << 1;
                else if(abs(a-l) >= x) cout << 2;
                else if(abs(r-b) >= x) cout << 2;
                else if(abs(b-l) >= x) cout << 3;
                else cout << -1;
            }
            else if(a > b) {
                if(abs(a-b) >= x) cout << 1;
                else if(abs(r-a) >= x) cout << 2;
                else if(abs(b-l) >= x) cout << 2;
                else if(abs(r-b) >= x) cout << 3;
                else cout << -1;
            }
        } else cout << -1;
        cout << endl;
    }

}
