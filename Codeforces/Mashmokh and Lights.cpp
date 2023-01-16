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
    vector<ll>v(n+1); v[0]=0;
    for(ll i{}; i<m; i++) {
        ll index; cin >> index;
        ll j = index;
        while(v[j] == 0)
            v[j++] = index;
    }
    for(ll i{1}; i<n+1; i++)
        cout << v[i] << " ";

}
