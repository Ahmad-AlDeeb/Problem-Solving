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
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        vector<vector<char>>grid(n,vector<char>(m));
        for(auto &r:grid) for(auto &c:r) cin >> c;

        for(ll i=n-2; i>=0; i--)
            for(ll j{}; j<m; j++)
                if(grid[i][j] == '*')
                    for(ll k{i}; k<n-1; k++) {
                        if(grid[k+1][j] == '.') {
                            grid[k][j]='.';
                            grid[k+1][j]='*';
                        } else break;
                    }

        for(auto &r:grid) {
            for(auto &c:r) cout << c;
            cout << endl;
        }
    }
}
