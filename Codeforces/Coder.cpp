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
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<vector<char>>mat(n,vector<char>(n));

    ll ans{}; bool coder{true};
    for(ll i{}; i<n; i++) {
        for(ll j{}; j<n; j++) {
            if(coder) {
                mat[i][j] = 'C';
                ans++;
            }
            else mat[i][j] = '.';
            coder = !coder;
        }
        if(n%2 == 0) coder = !coder;
    }

    cout << ans << endl;
    for(ll i{}; i<n; i++) {
        for (ll j{}; j < n; j++)
            cout << mat[i][j];
        cout << endl;
    }
}
