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
    ll n,k; cin >> n >> k;
    set<ll>s;
    while(n--) {
        ll l,r;
        cin >> l >> r;
        for(ll i{l}; i<=r; i++) s.insert(i);
    }
    if(s.size()%k == 0) cout << 0;
    else cout << k-s.size()%k;
}
