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
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll l,r; cin >> l >> r;
    ll ans{};
    for(ll k{}; (1LL<<k)/2<=r; k++)
        for(ll k2{}; k2<k-1; k2++) {
            ll year = (1LL << k)-1 -(1LL<<k2);
            if(year>=l && year <=r) ans++;
        }
    cout << ans;
}
