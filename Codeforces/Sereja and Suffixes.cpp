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
    ll n,m; cin >> n >> m;
    vector<ll>vec(n),ans(n); for(auto &i:vec) cin >> i;
    vector<bool>exist(10e5);

    ll distinct{};
    for(ll i{n-1}; i>=0; i--) {
        if(!exist[vec[i]]) {
            distinct++;
            exist[vec[i]]=true;
        }
        ans[i]=distinct;
    }


    while(m--) {
        ll query; cin >> query; query--;
        cout << ans[query] << endl;
    }
}
 
