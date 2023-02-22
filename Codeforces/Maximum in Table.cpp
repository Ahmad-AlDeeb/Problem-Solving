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
    vector<vector<ll>>mat (n,vector<ll>(n));

    for(ll i{}; i<n; i++)
        mat[0][i] = mat[i][0] = 1;

    for(ll i{1}; i<n; i++)
        for(ll j{1}; j<n; j++)
            mat[i][j] += (mat[i-1][j]+mat[i][j-1]);
    cout << mat[n-1][n-1];
}
