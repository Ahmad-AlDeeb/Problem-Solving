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
#include<map>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;

        ll sum_i{};
        for(ll i{1}; i<n; i++) sum_i += i;

        ll ans = 2*sum_i;
        for(ll i{n}; i>0; i--) {
            ans *= i;
            ans %= 1000000007;
        }
        cout << ans << endl;
    }
}
