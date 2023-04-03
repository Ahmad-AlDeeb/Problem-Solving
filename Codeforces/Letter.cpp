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
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

ll get_score(ll pts, ll time) {

    return max(3*pts/10, pts-pts/250*time);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,m; cin >> n >> m;
    vector<vector<char>>mat(n,vector<char>(m));
    for(auto &i:mat) for(auto &j:i) cin >> j;

    ll first_row,last_row;
    ll first_col{m},last_col{};
    bool found_first{false};
    for(ll i{}; i<n; i++) {
        for(ll j{}; j<m; j++) {
            if(mat[i][j] == '*') {
                if(!found_first) {first_row=i; found_first=true;}
                last_row = i;
                first_col = min(first_col,j);
                last_col = max(last_col,j);
            }
        }
    }

    for(ll i{first_row}; i<=last_row; i++) {
        for(ll j{first_col}; j<=last_col; j++)
            cout << mat[i][j];
        cout << endl;
    }
}
