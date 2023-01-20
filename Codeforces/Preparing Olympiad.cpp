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
    ll n,l,r,x; cin >> n >> l >> r >> x;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;

    ll ans{};
    for(ll i{}; i<pow(2,n); i++) {
        bitset<64>sub(i);
        if(sub.count() < 2) continue;

        vector<ll>prob; ll total{};
        for(ll j{}; j<64; j++)
            if(sub[j]) {prob.push_back(vec[j]); total+=vec[j];}
        sort(prob.begin(), prob.end());
        if(prob.back()-prob.front() >= x and total>=l && total<=r) ans++;
    }
    cout << ans;
}
